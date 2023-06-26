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
#define MAIN_SONG "sounds/cyberTheme.wav"
#define PACMAN_CHOMP "sounds/pacmanChomp.wav"
#define PACMAN_DEATH_SOUND "sounds/pacmanDeath.wav"
#define FPS 60

int main(void)
{
  if (!al_init())
  {
    std::cout << "Failed to initialize Allegro!" << std::endl;
    return -1;
  }

  al_init_image_addon();
  al_init_font_addon();
  al_init_ttf_addon();
  al_init_acodec_addon();
  al_install_audio();
  al_install_keyboard();

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

  al_reserve_samples(1);

  al_set_target_bitmap(al_get_backbuffer(display));

  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_timer_event_source(timer));
  al_start_timer(timer);

  bool running = true;
  bool redraw = true;
  ALLEGRO_EVENT event;
  ALLEGRO_TIMEOUT timeout;
  al_init_timeout(&timeout, 0.06);

  while (running)
  {
    al_wait_for_event(queue, &event);

    if (event.type == ALLEGRO_EVENT_TIMER)
    {
      if (event.timer.source == timer)
      {
        redraw = true;
      }
    }
    else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    {
      running = false;
    }

    if (redraw && al_is_event_queue_empty(queue))
    {
      redraw = false;

      // Draw code here

      al_flip_display();
    }
  }

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
  al_destroy_sample(pacmanDeathSound);

  return 0;
}
