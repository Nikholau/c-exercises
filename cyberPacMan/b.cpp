#include "b.h"
B::B(int x, int y) : Ghost()
{
  entityX = x;
  entityY = y;
}
B::~B() {}
void B::renderB(ALLEGRO_BITMAP *imgB, int sprite)
{
  al_draw_bitmap_region(imgB, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}
