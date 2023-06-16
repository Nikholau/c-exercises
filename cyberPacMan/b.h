#ifndef B
#define B

#include "ghost.h"
class B : public Ghost
{
public:
  B(int x, int y);
  ~B();
  void renderB(ALLEGRO_BITMAP *imgB, int sprite);
};

#endif // !B
