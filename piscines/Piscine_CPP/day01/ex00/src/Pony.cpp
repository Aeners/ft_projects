#include "../includes/Pony.hpp"

Pony::Pony(std::string color, std::string foods[]) : _color(color), _foodEaten( foods )
{
  return;
}

Pony::~Pony(void)
{
  return;
}

bool Pony::feed(std::string foodToGive)
{
  if (this._foodEatean.find(foodToGive))
}