#include "p.h"

P::P(int x, int y) : Ghost()
{
  entityX = x;
  entityY = y;
  ghostType = 3;
}
P::~P() {}
void P::chasePacman(std::vector<std::vector<char>> map, int pacX, int pacY)
{
  // TODO: implement P's unique chase method
}
void P::renderGhost(ALLEGRO_BITMAP *imgP, int sprite)
{
  al_draw_bitmap_region(imgP, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}
