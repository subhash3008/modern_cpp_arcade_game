#include "../include/entity.h"



// function to get the bounding rectangle of the sprite
sf::FloatRect Entity::getBoundingBox() const noexcept
{
  return sprite.getGlobalBounds();
}

// function to get the center of the sprite
sf::Vector2f Entity::getCenter() const noexcept
{
  auto box = this->getBoundingBox();
  return { (box.width / 2.0f), (box.height / 2.0f) };
}

// getter functions for position of sprite
float Entity::getX() const noexcept
{
  return sprite.getPosition().x;
}

float Entity::getY() const noexcept
{
  return sprite.getPosition().y;
}