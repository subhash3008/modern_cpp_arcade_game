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

  // set size of the ball
  this->sprite.scale(sf::Vector2f(.75f, .75f));

  // set velocity of the ball
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

  // adding rotation also gives floating effect
  // this->sprite.setRotation(this->sprite.getRotation() + 5.0f);

  // left boundary
  if (this->getX() < 0)
  {
    this->velocity.x = -this->velocity.x;
  }

  // right boundary
  if (this->getX() > (constants::window_width - 16))
  {
    this->velocity.x = -this->velocity.x;
  }

  // Top boundary
  if (this->getY() < 0)
  {
    this->velocity.y = -this->velocity.y;
  }

  // Bottom Boundary
  if (this->getY() > (constants::window_height - 16))
  {
    this->velocity.y = -this->velocity.y;
  }
}

void
Ball::draw(sf::RenderWindow& window)
{
  // draw the buffer window
  window.draw(this->sprite);
}

void
Ball::moveUp() noexcept
{
  this->velocity.y = -(constants::ball_speed);
}

void
Ball::moveLeft() noexcept
{
  this->velocity.x = -(constants::ball_speed);
}

void
Ball::moveRight() noexcept
{
  this->velocity.x = -(constants::ball_speed);
}