#include "../include/paddle.h"

// initialize texture
sf::Texture Paddle::texture;

Paddle::Paddle(float x, float y): MovingEntity()
{
  // load texture from File
  this->texture.loadFromFile("paddle.png");
  this->sprite.setTexture(this->texture);

  // set position and size
  this->sprite.setPosition(x, y);
  this->sprite.scale({ .5f, .75f });

  // set velocity
  this->velocity = { 0.0f, 0.0f };

}

void
Paddle::update()
{
  this->sprite.move(this->velocity);
}

void
Paddle::draw(sf::RenderWindow& window)
{
  window.draw(this->sprite);
}