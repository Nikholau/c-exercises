#include "ghost.h"

Ghost::Ghost()
{
  moveSpeed = 2.0;
  entityHeight = 32;
  entityWidth = 32;
  entitySize = 32;
  randomDirection = 0;
}

Ghost::~Ghost() {}

void Ghost::newDirection(std::vector<std::vector<char>> map)
{
  bool canGoUp, canGoDown, canGoLeft, canGoRight;

  if (checkEntityCollisionUp(map))
  {
    canGoUp = true;
  }
  else
  {
    canGoUp = false;
  }

  if (checkEntityCollisionDown(map))
  {
    canGoDown = true;
  }
  else
  {
    canGoDown = false;
  }

  if (checkEntityCollisionLeft(map))
  {
    canGoLeft = true;
  }
  else
  {
    canGoLeft = false;
  }

  if (checkEntityCollisionRight(map))
  {
    canGoRight = true;
  }
  else
  {
    canGoRight = false;
  }

  if (canGoLeft && !canGoRight && !canGoUp && !canGoDown)
  {
    checkEntityMovement(ALLEGRO_KEY_LEFT, map);
  }

  if (!canGoLeft && canGoRight && !canGoUp && !canGoDown)
  {
    checkEntityMovement(ALLEGRO_KEY_RIGHT, map);
  }

  if (!canGoLeft && !canGoRight && canGoUp && !canGoDown)
  {
    checkEntityMovement(ALLEGRO_KEY_UP, map);
  }

  if (!canGoLeft && !canGoRight && !canGoUp && canGoDown)
  {
    checkEntityMovement(ALLEGRO_KEY_DOWN, map);
  }

  if (canGoUp && canGoLeft)
  {
    randomDirection = std::rand() % 2;
    if (randomDirection == 0)
    {
      checkEntityMovement(ALLEGRO_KEY_UP, map);
    }
    else
    {
      checkEntityMovement(ALLEGRO_KEY_LEFT, map);
    }
  }

  if (canGoUp && canGoDown)
  {
    randomDirection = std::rand() % 2;
    if (randomDirection == 0)
    {
      checkEntityMovement(ALLEGRO_KEY_UP, map);
    }
    else
    {
      checkEntityMovement(ALLEGRO_KEY_DOWN, map);
    }
  }

  if (canGoUp && canGoRight)
  {
    randomDirection = std::rand() % 2;
    if (randomDirection == 0)
    {
      checkEntityMovement(ALLEGRO_KEY_UP, map);
    }
    else
    {
      checkEntityMovement(ALLEGRO_KEY_RIGHT, map);
    }
  }

  if (canGoDown && canGoLeft)
  {
    randomDirection = std::rand() % 2;
    if (randomDirection == 0)
    {
      checkEntityMovement(ALLEGRO_KEY_DOWN, map);
    }
    else
    {
      checkEntityMovement(ALLEGRO_KEY_LEFT, map);
    }
  }

  if (canGoDown && canGoRight)
  {
    randomDirection = std::rand() % 2;
    if (randomDirection == 0)
    {
      checkEntityMovement(ALLEGRO_KEY_DOWN, map);
    }
    else
    {
      checkEntityMovement(ALLEGRO_KEY_RIGHT, map);
    }
  }

  if (canGoLeft && canGoRight)
  {
    randomDirection = std::rand() % 2;
    if (randomDirection == 0)
    {
      checkEntityMovement(ALLEGRO_KEY_LEFT, map);
    }
    else
    {
      checkEntityMovement(ALLEGRO_KEY_RIGHT, map);
    }
  }

  if (canGoUp && canGoLeft && canGoRight)
  {
    randomDirection = std::rand() % 3;
    if (randomDirection == 0)
    {
      checkEntityMovement(ALLEGRO_KEY_UP, map);
    }
    else if (randomDirection == 1)
    {
      checkEntityMovement(ALLEGRO_KEY_LEFT, map);
    }
    else
    {
      checkEntityMovement(ALLEGRO_KEY_RIGHT, map);
    }
  }

  if (canGoUp && canGoLeft && canGoDown)
  {
    randomDirection = std::rand() % 3;
    if (randomDirection == 0)
    {
      checkEntityMovement(ALLEGRO_KEY_UP, map);
    }
    else if (randomDirection == 1)
    {
      checkEntityMovement(ALLEGRO_KEY_LEFT, map);
    }
    else
    {
      checkEntityMovement(ALLEGRO_KEY_DOWN, map);
    }
  }

  if (canGoUp && canGoRight && canGoDown)
  {
    randomDirection = std::rand() % 3;
    if (randomDirection == 0)
    {
      checkEntityMovement(ALLEGRO_KEY_UP, map);
    }
    else if (randomDirection == 1)
    {
      checkEntityMovement(ALLEGRO_KEY_RIGHT, map);
    }
    else
    {
      checkEntityMovement(ALLEGRO_KEY_DOWN, map);
    }
  }

  if (canGoDown && canGoLeft && canGoRight)
  {
    randomDirection = std::rand() % 3;
    if (randomDirection == 0)
    {
      checkEntityMovement(ALLEGRO_KEY_DOWN, map);
    }
    else if (randomDirection == 1)
    {
      checkEntityMovement(ALLEGRO_KEY_LEFT, map);
    }
    else
    {
      checkEntityMovement(ALLEGRO_KEY_RIGHT, map);
    }
  }

  if (canGoDown && canGoUp && canGoLeft && canGoRight)
  {
    randomDirection = std::rand() % 4;
    if (randomDirection == 0)
    {
      checkEntityMovement(ALLEGRO_KEY_DOWN, map);
    }
    else if (randomDirection == 1)
    {
      checkEntityMovement(ALLEGRO_KEY_UP, map);
    }
    else if (randomDirection == 2)
    {
      checkEntityMovement(ALLEGRO_KEY_LEFT, map);
    }
    else
    {
      checkEntityMovement(ALLEGRO_KEY_RIGHT, map);
    }
  }
}

void Ghost::moveRandom(std::vector<std::vector<char>> map)
{
  bool isWalking;

  if (moveUp || moveDown || moveLeft || moveRight)
  {
    isWalking = true;
  }
  else
  {
    isWalking = false;
  }

  if (isWalking && checkEntityCollisionUp(map) && checkEntityCollisionDown(map) && checkEntityCollisionLeft(map) && checkEntityCollisionRight(map))
  {
    newDirection(map);
  }

  if (isWalking && checkEntityCollisionUp(map) && checkEntityCollisionDown(map) && checkEntityCollisionLeft(map))
  {
    newDirection(map);
  }

  if (isWalking && checkEntityCollisionUp(map) && checkEntityCollisionDown(map) && checkEntityCollisionRight(map))
  {
    newDirection(map);
  }

  if (isWalking && checkEntityCollisionUp(map) && checkEntityCollisionRight(map) && checkEntityCollisionLeft(map))
  {
    newDirection(map);
  }

  if (isWalking && checkEntityCollisionDown(map) && checkEntityCollisionLeft(map) && checkEntityCollisionRight(map))
  {
    newDirection(map);
  }

  if (isWalking && checkEntityCollisionDown(map) && checkEntityCollisionLeft(map) && checkEntityCollisionUp(map))
  {
    newDirection(map);
  }

  if (isWalking && checkEntityCollisionDown(map) && checkEntityCollisionRight(map) && checkEntityCollisionUp(map))
  {
    newDirection(map);
  }

  if (isWalking && checkEntityCollisionLeft(map) && checkEntityCollisionRight(map) && checkEntityCollisionUp(map))
  {
    newDirection(map);
  }

  if (isWalking && checkEntityCollisionDown(map) && checkEntityCollisionLeft(map))
  {
    newDirection(map);
  }

  if (isWalking && checkEntityCollisionDown(map) && checkEntityCollisionRight(map))
  {
    newDirection(map);
  }

  if (isWalking && checkEntityCollisionUp(map) && checkEntityCollisionLeft(map))
  {
    newDirection(map);
  }

  if (isWalking && checkEntityCollisionUp(map) && checkEntityCollisionRight(map))
  {
    newDirection(map);
  }

  if (isWalking && checkEntityCollisionLeft(map) && checkEntityCollisionRight(map))
  {
    newDirection(map);
  }

  if (isWalking && checkEntityCollisionUp(map) && checkEntityCollisionDown(map))
  {
    newDirection(map);
  }

  if (isWalking && checkEntityCollisionLeft(map))
  {
    newDirection(map);
  }

  if (isWalking && checkEntityCollisionRight(map))
  {
    newDirection(map);
  }

  if (isWalking && checkEntityCollisionUp(map))
  {
    newDirection(map);
  }

  if (isWalking && checkEntityCollisionDown(map))
  {
    newDirection(map);
  }
}

void Ghost::update(std::vector<std::vector<char>> map)
{
  moveRandom(map);
}
