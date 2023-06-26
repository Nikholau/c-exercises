#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include "map.h"
#include "pacman.h"
#include "ghost.h"
#include "b.h"
#include "p.h"
#include "i.h"
#include "c.h"

#define PACMAN_SPRITE "sprites/pacman.png"
#define B_SPRITE "sprites/b.png"
#define P_SPRITE "sprites/p.png"
#define I_SPRITE "sprites/i.png"
#define C_SPRITE "sprites/c.png"
#define MAP_SPRITE "sprites/mapaoverlay.png"
#define FONT "fonts/arial.ttf"
#define MAIN_SONG "sounds/cyberTheme.wav"
#define PACMAN_CHOMP "sounds/pacmanChomp.wav"
#define PACMAN_DEATH_SOUND "sounds/pacmanDeath.wav"
#define FPS 60

int main(void)
{
  al_init();
  al_init_image_addon();
  al_init_font_addon();
  al_init_ttf_addon();
  al_init_acodec_addon();
  al_install_audio();
  al_install_keyboard();

  if (!al_init())
  {
    std::cout << "Failed to initialize Allegro!" << std::endl;
    return -1;
  }

  ALLEGRO_DISPLAY *display = al_create_display(608, 672);
  if (!display)
  {
    std::cout << "Failed to create display!" << std::endl;
    return -1;
  }

  ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
  if (!queue)
  {
    std::cout << "Failed to create event queue!" << std::endl;
    al_destroy_display(display);
    return -1;
  }

  ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
  if (!timer)
  {
    std::cout << "Failed to create timer!" << std::endl;
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    return -1;
  }

  al_reserve_samples(4);

  ALLEGRO_BITMAP *pacman_sprite = al_load_bitmap(PACMAN_SPRITE);
  ALLEGRO_BITMAP *b_sprite = al_load_bitmap(B_SPRITE);
  ALLEGRO_BITMAP *p_sprite = al_load_bitmap(P_SPRITE);
  ALLEGRO_BITMAP *i_sprite = al_load_bitmap(I_SPRITE);
  ALLEGRO_BITMAP *c_sprite = al_load_bitmap(C_SPRITE);
  ALLEGRO_BITMAP *map_sprite = al_load_bitmap(MAP_SPRITE);

  if (!pacman_sprite || !b_sprite || !p_sprite || !i_sprite || !c_sprite)
  {
    std::cout << "Failed to load sprite(s)!" << std::endl;
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    return -1;
  }

  ALLEGRO_FONT *font = al_load_font("fonts/arial.ttf", 0, 0);
  if (!font)
  {
    std::cout << "Failed to load font!" << std::endl;
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_bitmap(pacman_sprite);
    al_destroy_bitmap(b_sprite);
    al_destroy_bitmap(p_sprite);
    al_destroy_bitmap(i_sprite);
    al_destroy_bitmap(c_sprite);
    return -1;
  }

  ALLEGRO_SAMPLE *mainSongAudio = al_load_sample(MAIN_SONG);
  if (!mainSongAudio)
  {
    std::cout << "Failed to load audio sample!" << std::endl;
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_bitmap(pacman_sprite);
    al_destroy_bitmap(b_sprite);
    al_destroy_bitmap(p_sprite);
    al_destroy_bitmap(i_sprite);
    al_destroy_bitmap(c_sprite);
    al_destroy_font(font);
    return -1;
  }

  ALLEGRO_SAMPLE *pacmanEatAudio = al_load_sample(PACMAN_CHOMP);
  if (!pacmanEatAudio)
  {
    std::cout << "Failed to load audio sample!" << std::endl;
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_bitmap(pacman_sprite);
    al_destroy_bitmap(b_sprite);
    al_destroy_bitmap(p_sprite);
    al_destroy_bitmap(i_sprite);
    al_destroy_bitmap(c_sprite);
    al_destroy_font(font);
    al_destroy_sample(mainSongAudio);
    return -1;
  }

  ALLEGRO_SAMPLE *pacmanDeathSound = al_load_sample(PACMAN_DEATH_SOUND);
  if (!pacmanDeathSound)
  {
    std::cout << "Failed to load audio sample!" << std::endl;
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_bitmap(pacman_sprite);
    al_destroy_bitmap(b_sprite);
    al_destroy_bitmap(p_sprite);
    al_destroy_bitmap(i_sprite);
    al_destroy_bitmap(c_sprite);
    al_destroy_font(font);
    al_destroy_sample(mainSongAudio);
    al_destroy_sample(pacmanEatAudio);
    return -1;
  }
  ALLEGRO_SAMPLE_ID mainSongID;
  al_reserve_samples(3);
  std::vector<std::vector<char>> mapa; // Create the map array

  al_set_target_bitmap(al_get_backbuffer(display));

  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_timer_event_source(timer));
  al_start_timer(timer);

  bool running = true;
  bool redraw = true;
  bool teclas[255] = {false};
  int sprite = 0, fator = 1, tempo, miliseg = 200;
  ALLEGRO_EVENT event;
  ALLEGRO_TIMEOUT timeout;
  al_init_timeout(&timeout, 0.06);

  // Objects
  Map gameMap;
  Pacman playerPacman(288, 480); // 288, 480
  B ghostB(32, 32);              // 288, 256 -> 32, 32 spawn in box -> spawn on edges
  P ghostP(544, 32);             // 320, 288 -> 544, 32
  I ghostI(544, 608);            // 288, 288 -> 544, 608
  C ghostC(32, 608);             // 256, 288 -> 32, 608

  al_play_sample(mainSongAudio, 0.3, 0, 1, ALLEGRO_PLAYMODE_LOOP, &mainSongID);

  gameMap.loadMap("map.txt", mapa);

  Ghost *ghostVet[4];
  ghostVet[0] = &ghostC;
  ghostVet[1] = &ghostP;
  ghostVet[2] = &ghostI;
  ghostVet[3] = &ghostB;

  while (running)
  {
    ALLEGRO_EVENT event;
    al_wait_for_event(queue, &event);
    tempo = al_get_timer_count(timer);

    // Player functions
    playerPacman.calculateEntityPosition();
    playerPacman.checkCoinCollision(mapa, pacmanEatAudio);
    playerPacman.checkTeleportCollision(mapa);
    playerPacman.checkEntityMovement(playerPacman.getNextMove(), mapa);
    playerPacman.moveEntity(mapa);

    // Ghost functions, we only have Blinky (ghostVet[3]) in chase mode
    for (int i = 0; i < 4; i++)
    {
      ghostVet[i]->calculateEntityPosition();
      ghostVet[i]->checkTeleportCollision(mapa);
    }
    for (int i = 0; i < 3; i++)
    {
      ghostVet[i]->randomDirection(mapa);
      ghostVet[i]->moveEntity(mapa);
    }

    ghostVet[3]->chasePacman(mapa, playerPacman.getEntityConvertedX(), playerPacman.getEntityConvertedY());
    ghostVet[3]->checkEntityMovement(ghostVet[3]->getNextMove(), mapa);
    ghostVet[3]->moveEntity(mapa);

    if (event.type == ALLEGRO_EVENT_TIMER)
    {
      // Timer to change the bitmap, used for animating PACMAN
      if (tempo == ((FPS * miliseg) / 1000) || tempo > ((FPS * miliseg) / 1000))
      {
        al_set_timer_count(timer, 0);
        sprite = sprite + fator;
        if (sprite == 0)
          fator = 1;
        if (sprite == 1)
          fator = -1; // As our sprite only has an animation composed of two images, "sprite == 1"
      }

      // Receive the command and store it until it can be executed
      if (teclas[ALLEGRO_KEY_UP])
      {
        playerPacman.setNextMove(ALLEGRO_KEY_UP, mapa);
      }
      if (teclas[ALLEGRO_KEY_DOWN])
      {
        playerPacman.setNextMove(ALLEGRO_KEY_DOWN, mapa);
      }
      if (teclas[ALLEGRO_KEY_LEFT])
      {
        playerPacman.setNextMove(ALLEGRO_KEY_LEFT, mapa);
      }
      if (teclas[ALLEGRO_KEY_RIGHT])
      {
        playerPacman.setNextMove(ALLEGRO_KEY_RIGHT, mapa);
      }

      redraw = true;
    }

    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
      teclas[event.keyboard.keycode] = true;
    }
    if (event.type == ALLEGRO_EVENT_KEY_UP)
    {
      teclas[event.keyboard.keycode] = false;
    }

    // Redraw function, basically calls every object's draw function to update it's position and flip the display
    if (redraw && al_is_event_queue_empty(queue))
    {
      redraw = false;
      al_clear_to_color(al_map_rgb(0, 0, 0));
      gameMap.renderMap(mapa);
      al_draw_bitmap(map_sprite, 0, -32, 0);

      playerPacman.renderPacman(pacman_sprite, sprite);
      ghostVet[0]->renderGhost(c_sprite, sprite);
      ghostVet[1]->renderGhost(p_sprite, sprite);
      ghostVet[2]->renderGhost(i_sprite, sprite);
      ghostVet[3]->renderGhost(b_sprite, sprite);

      al_draw_textf(font, al_map_rgb(255, 255, 255), 32, 0, 0, "Score: %d", playerPacman.getScore());
      al_flip_display();
    }

    // End the game when closing the window
    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    {
      running = false;
    }
    // End the game when there's no more coins left
    if (playerPacman.getScore() >= 151)
    {
      al_rest(3);
      running = false;
    }
    // End the game when PacMan collides with a ghost
    if (playerPacman.checkGhostCollision(ghostB, ghostP, ghostI, ghostC))
    {
      al_stop_sample(&mainSongID);
      al_play_sample(pacmanDeathSound, 0.6, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
      al_rest(3);
      running = false;
    }
  }

  al_uninstall_keyboard();
  al_destroy_sample(mainSongAudio);
  al_destroy_sample(pacmanEatAudio);
  al_destroy_sample(pacmanDeathSound);
  al_uninstall_audio();
  al_destroy_bitmap(pacman_sprite);
  al_destroy_bitmap(b_sprite);
  al_destroy_bitmap(p_sprite);
  al_destroy_bitmap(i_sprite);
  al_destroy_bitmap(c_sprite);
  al_destroy_font(font);
  al_destroy_display(display);
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);

  return 0;
}
