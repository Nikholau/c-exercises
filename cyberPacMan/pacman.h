#ifndef PACMAN_H
#define PACMAN_H

#include "entity.h"
#include "ghost.h"
#include "b.h"
#include "p.h"
#include "i.h"
#include "c.h"
#include <vector>
#include <math.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_audio.h>

class Pacman : public Entity
{
public:
  Pacman(int x, int y);
  ~Pacman();
  int getScore();
  void checkCoinCollision(std::vector<std::vector<char>> &map, ALLEGRO_SAMPLE *pacmanChomp);
  bool checkGhostCollision(B &f1, P &f2, I &f3, C &f4);
  void renderPacman(ALLEGRO_BITMAP *imgPacman, int sprite);

private:
  int score;
};

#endif // PACMAN_H
