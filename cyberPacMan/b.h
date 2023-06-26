#ifndef B_H
#define B_H

#include "ghost.h"

class B : public Ghost
{
public:
  B(int x, int y);
  ~B();
  void renderB(ALLEGRO_BITMAP *imgB, int sprite);
};

#endif // B_H
