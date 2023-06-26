#ifndef I_H
#define I_H

#include "ghost.h"

class I : public Ghost
{
public:
  I(int x, int y);
  ~I();
  virtual void renderGhost(ALLEGRO_BITMAP *img, int sprite);
  virtual void chasePacman(std::vector<std::vector<char>> mapa, int pacmanX, int pacmanY);
};

#endif // I_H
