#ifndef B_H
#define B_H

#include "ghost.h"

class B : public Ghost
{
public:
  B(int x, int y);
  ~B();
  void renderGhost(ALLEGRO_BITMAP *img, int sprite);
  virtual void chasePacman(std::vector<std::vector<char>> mapa, int pacX, int pacY);
};

#endif
