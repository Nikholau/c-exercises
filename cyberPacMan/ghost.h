#ifndef GHOST_H
#define GHOST_H

#include "entity.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

class Ghost : public Entity
{
public:
  Ghost();
  ~Ghost();
  virtual void chasePacman(std::vector<std::vector<char>> mapa, int pacmanX, int pacmanY) = 0;
  void randomDirection(std::vector<std::vector<char>> mapa);
  void checkRandomDirection(std::vector<std::vector<char>> mapa);
  virtual void renderGhost(ALLEGRO_BITMAP *img, int sprite) = 0;

protected:
  int ghostType;
};

#endif // !GHOST_H