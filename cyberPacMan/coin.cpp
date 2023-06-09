#include "coin.h"
#define COIN_SPRITE "sprites/coin.png"

Coin::Coin()
{
  coin_sprite = al_load_bitmap(COIN_SPRITE);
}

Coin::~Coin()
{
  al_destroy_bitmap(coin_sprite);
}

void Coin::renderCoin(int linha, int coluna)
{
  al_draw_bitmap(coin_sprite, coluna * 32, linha * 32, 0);
}