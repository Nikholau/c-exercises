#include "i.h"
I::I(int x, int y) : Ghost()
{
  entityX = x;
  entityY = y;
}
I::~I() {}
void I::renderI(ALLEGRO_BITMAP *imgI, int sprite)
{
  al_draw_bitmap_region(imgI, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}