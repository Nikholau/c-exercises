#include "c.h"
C::C(int x, int y) : Ghost()
{
  entityX = x;
  entityY = y;
}
C::~C() {}
void C::chasePacman(std::vector<std::vector<char>> map, int pacX, int pacY)
{
  int bX = this->getEntityConvertedX();
  int bY = this->getEntityConvertedY();
  int currentMove = this->getCurrentMove(); // Get the current direction of B, 0 - RIGHT, 1 - DOWN, 2 - LEFT, 3 - UP

  enum moveKeys
  {
    RIGHT,
    DOWN,
    LEFT,
    UP
  };

  if (bX == 9 && bY == 8)
  {
    this->setNextMove(ALLEGRO_KEY_UP, map);
    return;
  }

  if (bX > pacX && bY > pacY)
  {
    if (currentMove != RIGHT && checkEntityCollisionLeft(map))
    {
      this->setNextMove(ALLEGRO_KEY_LEFT, map);
      return;
    }
    else if (currentMove != DOWN && checkEntityCollisionUp(map))
    {
      this->setNextMove(ALLEGRO_KEY_UP, map);
      return;
    }
    else if (currentMove != LEFT && checkEntityCollisionRight(map))
    {
      this->setNextMove(ALLEGRO_KEY_RIGHT, map);
      return;
    }
    else if (currentMove != UP && checkEntityCollisionDown(map))
    {
      this->setNextMove(ALLEGRO_KEY_DOWN, map);
      return;
    }
  }
  else if (bX > pacX && bY < pacY)
  {
    if (currentMove != RIGHT && checkEntityCollisionLeft(map))
    {
      this->setNextMove(ALLEGRO_KEY_LEFT, map);
      return;
    }
    else if (currentMove != UP && checkEntityCollisionDown(map))
    {
      this->setNextMove(ALLEGRO_KEY_DOWN, map);
      return;
    }
    else if (currentMove != LEFT && checkEntityCollisionRight(map))
    {
      this->setNextMove(ALLEGRO_KEY_RIGHT, map);
      return;
    }
    else if (currentMove != DOWN && checkEntityCollisionUp(map))
    {
      this->setNextMove(ALLEGRO_KEY_UP, map);
      return;
    }
  }
  else if (bX > pacX && bY == pacY)
  {
    if (currentMove != RIGHT && checkEntityCollisionLeft(map))
    {
      this->setNextMove(ALLEGRO_KEY_LEFT, map);
      return;
    }
    else if (currentMove != UP && checkEntityCollisionDown(map))
    {
      this->setNextMove(ALLEGRO_KEY_DOWN, map);
      return;
    }
    else if (currentMove != DOWN && checkEntityCollisionUp(map))
    {
      this->setNextMove(ALLEGRO_KEY_UP, map);
      return;
    }
    else if (currentMove != LEFT && checkEntityCollisionRight(map))
    {
      this->setNextMove(ALLEGRO_KEY_RIGHT, map);
      return;
    }
  }
  else if (bX < pacX && bY == pacY)
  {
    if (currentMove != LEFT && checkEntityCollisionRight(map))
    {
      this->setNextMove(ALLEGRO_KEY_RIGHT, map);
      return;
    }
    else if (currentMove != UP && checkEntityCollisionDown(map))
    {
      this->setNextMove(ALLEGRO_KEY_DOWN, map);
      return;
    }
    else if (currentMove != DOWN && checkEntityCollisionUp(map))
    {
      this->setNextMove(ALLEGRO_KEY_UP, map);
      return;
    }
    else if (currentMove != RIGHT && checkEntityCollisionLeft(map))
    {
      this->setNextMove(ALLEGRO_KEY_LEFT, map);
      return;
    }
  }
  else if (bX == pacX && bY < pacY)
  {
    if (currentMove != UP && checkEntityCollisionDown(map))
    {
      this->setNextMove(ALLEGRO_KEY_DOWN, map);
      return;
    }
    else if (currentMove != RIGHT && checkEntityCollisionLeft(map))
    {
      this->setNextMove(ALLEGRO_KEY_LEFT, map);
      return;
    }
    else if (currentMove != LEFT && checkEntityCollisionRight(map))
    {
      this->setNextMove(ALLEGRO_KEY_RIGHT, map);
      return;
    }
    else if (currentMove != DOWN && checkEntityCollisionUp(map))
    {
      this->setNextMove(ALLEGRO_KEY_UP, map);
      return;
    }
  }
  else if (bX == pacX && bY > pacY)
  {
    if (currentMove != DOWN && checkEntityCollisionUp(map))
    {
      this->setNextMove(ALLEGRO_KEY_UP, map);
      return;
    }
    else if (currentMove != LEFT && checkEntityCollisionRight(map))
    {
      this->setNextMove(ALLEGRO_KEY_RIGHT, map);
      return;
    }
    else if (currentMove != RIGHT && checkEntityCollisionLeft(map))
    {
      this->setNextMove(ALLEGRO_KEY_LEFT, map);
      return;
    }
    else if (currentMove != UP && checkEntityCollisionDown(map))
    {
      this->setNextMove(ALLEGRO_KEY_DOWN, map);
      return;
    }
  }
  else if (bX < pacX && bY > pacY)
  {
    if (currentMove != LEFT && checkEntityCollisionRight(map))
    {
      this->setNextMove(ALLEGRO_KEY_RIGHT, map);
      return;
    }
    else if (currentMove != DOWN && checkEntityCollisionUp(map))
    {
      this->setNextMove(ALLEGRO_KEY_UP, map);
      return;
    }
    else if (currentMove != RIGHT && checkEntityCollisionLeft(map))
    {
      this->setNextMove(ALLEGRO_KEY_LEFT, map);
      return;
    }
    else if (currentMove != UP && checkEntityCollisionDown(map))
    {
      this->setNextMove(ALLEGRO_KEY_DOWN, map);
      return;
    }
  }
  else if (bX < pacX && bY < pacY)
  {
    if (currentMove != LEFT && checkEntityCollisionRight(map))
    {
      this->setNextMove(ALLEGRO_KEY_RIGHT, map);
      return;
    }
    else if (currentMove != UP && checkEntityCollisionDown(map))
    {
      this->setNextMove(ALLEGRO_KEY_DOWN, map);
      return;
    }
    else if (currentMove != RIGHT && checkEntityCollisionLeft(map))
    {
      this->setNextMove(ALLEGRO_KEY_LEFT, map);
      return;
    }
    else if (currentMove != DOWN && checkEntityCollisionUp(map))
    {
      this->setNextMove(ALLEGRO_KEY_UP, map);
      return;
    }
  }
}

void C::renderGhost(ALLEGRO_BITMAP *imgC, int sprite)
{
  al_draw_bitmap_region(imgC, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}