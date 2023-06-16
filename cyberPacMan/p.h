#ifndef P
#define P

#include "ghost.h"
class P : public Ghost
{
public:
  P(int x, int y);
  ~P();
  void renderP(ALLEGRO_BITMAP *imgP, int sprite);
};

#endif // !P
