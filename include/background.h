#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "constants.h"
#include "entity.h"

// class to represent the background
class Background : public Entity
{
  static sf::Texture texture;

public:
  // constructor
  Background(float x, float y);

  void update() override;
  void draw(sf::RenderWindow& window) override;
};

#endif