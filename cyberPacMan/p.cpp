#include "p.h"
P::P(int x, int y) : Ghost()
{
  entityX = x;
  entityY = y;
}
P::~P() {}
void P::renderP(ALLEGRO_BITMAP *imgP, int sprite)
{
  al_draw_bitmap_region(imgP, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}