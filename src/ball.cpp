#include "../include/ball.h"

// initialize the texture of the ball
sf::Texture Ball::texture;

Ball::Ball(float x, float y) : MovingEntity()
{
  // load the ball texture
  this->texture.loadFromFile("ball.png");
  this->sprite.setTexture(this->texture);

  // set initial position
  this->sprite.setPosition(x, y);
  this->velocity = {
    constants::ball_speed,
    constants::ball_speed
  };
}

void
Ball::update()
{
  // update the ball for new position
  this->sprite.move(this->velocity);
}

void
Ball::draw(sf::RenderWindow& window)
{
  // draw the buffer window
  window.draw(this->sprite);
}