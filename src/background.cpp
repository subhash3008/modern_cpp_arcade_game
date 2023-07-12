#include "../include/background.h"

sf::Texture Background::texture;

Background::Background(float x, float y): Entity()
{
  // load the texture file
  this->texture.loadFromFile("bg.jpg");

  this->sprite.setTexture(texture);

  // set initial position of the background
  this->sprite.setPosition(x, y);
}

void
Background::update()
{
  // do nothing
}

void
Background::draw(sf::RenderWindow& window)
{
  window.draw(this->sprite);
}