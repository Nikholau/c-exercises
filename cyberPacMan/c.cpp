#include "c.h"
C::C(int x, int y) : Ghost()
{
  entityX = x;
  entityY = y;
}
C::~C() {}
void C::renderC(ALLEGRO_BITMAP *imgC, int sprite)
{
  al_draw_bitmap_region(imgC, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}