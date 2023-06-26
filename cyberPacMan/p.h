#ifndef P_H
#define P_H

#include "ghost.h"

class P : public Ghost
{
public:
  P(int x, int y);
  ~P();
  virtual void renderGhost(ALLEGRO_BITMAP *img, int sprite);
  virtual void chasePacman(std::vector<std::vector<char>> mapa, int pacmanX, int pacmanY);
};

#endif // !P_H
