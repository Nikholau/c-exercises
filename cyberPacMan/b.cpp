#include "b.h"
B::B(int x, int y) : Ghost()
{
  entityX = x;
  entityY = y;
  this->ghostType = 1;
}
B::~B() {}
void B::chasePacman(std::vector<std::vector<char>> map, int pacX, int pacY)
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
  { // Prevent B from going back into the box
    this->setNextMove(ALLEGRO_KEY_UP, map);
    return;
  }

  if (bX > pacX && bY > pacY)
  { // B is to the right of Pacman and below Pacman
    // PRIORITY: MOVE LEFT -> MOVE UP
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
  { // B is to the right of Pacman and above Pacman
    // PRIORITY: MOVE LEFT -> MOVE DOWN
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
  { // B is to the right of Pacman and at the same height as Pacman
    // PRIORITY: MOVE LEFT -> MOVE DOWN
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
  { // B is to the left of Pacman and at the same height as Pacman
    // PRIORITY: MOVE RIGHT -> MOVE DOWN
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
  { // B is in the same column as Pacman and above Pacman
    // PRIORITY: MOVE DOWN -> MOVE HORIZONTALLY
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
  { // B is in the same column as Pacman and below Pacman
    // PRIORITY: MOVE UP -> MOVE HORIZONTALLY
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
  { // B is to the left of Pacman and below Pacman
    // PRIORITY: MOVE RIGHT -> MOVE UP
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
  { // B is to the left of Pacman and above Pacman
    // PRIORITY: MOVE RIGHT -> MOVE DOWN
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
void B::renderGhost(ALLEGRO_BITMAP *imgB, int sprite)
{
  al_draw_bitmap_region(imgB, direction * entityWidth, sprite * entityHeight, entityWidth, entityHeight, getEntityX(), getEntityY(), 0);
}
