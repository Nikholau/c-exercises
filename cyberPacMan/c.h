#ifndef C_H
#define C_H

#include "ghost.h"

class C : public Ghost
{
public:
  C(int x, int y);
  ~C();
  virtual void renderGhost(ALLEGRO_BITMAP *img, int sprite);
  virtual void chasePacman(std::vector<std::vector<char>> mapa, int pacmanX, int pacmanY);
};

#endif // C_H
