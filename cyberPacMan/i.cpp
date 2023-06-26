#include "i.h"
I::I(int x, int y) : Ghost()
{
  entityX = x;
  entityY = y;
}
I::~I() {}
void I::chasePacman(std::vector<std::vector<char>> map, int pacX, int pacY)
{
  // TODO: implement I's unique chase method
}
void I::renderGhost(ALLEGRO_BITMAP *imgI, int sprite)
{
  al_draw_bitmap_region(imgI, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}
