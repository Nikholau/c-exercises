#ifndef C
#define C

#include "ghost.h"
class C : public Ghost
{
public:
  C(int x, int y);
  ~C();
  void renderC(ALLEGRO_BITMAP *imgC, int sprite);
};

#endif // !C
