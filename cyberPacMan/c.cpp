#include "c.h"
C::C(int x, int y) : Ghost()
{
  entityX = x;
  entityY = y;
}
C::~C() {}
void C::chasePacman(std::vector<std::vector<char>> map, int pacX, int pacY)
{
  // TODO: implement C's unique chase method
}
void C::renderGhost(ALLEGRO_BITMAP *imgC, int sprite)
{
  al_draw_bitmap_region(imgC, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}