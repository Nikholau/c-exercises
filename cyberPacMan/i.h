#ifndef I_H
#define I_H

#include "ghost.h"

class I : public Ghost
{
public:
  I(int x, int y);
  ~I();
  void renderI(ALLEGRO_BITMAP *imgI, int sprite);
};

#endif // I_H
