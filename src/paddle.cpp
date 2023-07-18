#include "../include/paddle.h"
#include <iostream>

// initialize texture
sf::Texture Paddle::texture;

// initializing paddle rectangle
sf::RoundedRectangleShape Paddle::padRect;

Paddle::Paddle(float x, float y): MovingEntity()
{
  // load texture from File
  // this->texture.loadFromFile("paddle.png");
  // this->sprite.setTexture(this->texture);

  // set properties of paddle shape
  this->padRect.setSize(sf::Vector2f(
    {
    constants::paddle_width,
    constants::paddle_height
    }
  ));
  this->padRect.setPosition(sf::Vector2f(
    {
      x, y
    }
  ));
  auto padRectColor = sf::Color{ 75, 0, 130 };
  this->padRect.setFillColor(padRectColor);

  this->padRect.setCornerPointCount(100);
  this->padRect.setCornersRadius(15.0f);

  // set position
  // this->sprite.setPosition(x, y);

  // set velocity
  this->velocity = { 0.0f, 0.0f };

}

void
Paddle::update()
{
  processPlayerInput();

  if (this->isPaddleMoving)
  {
    // this->sprite.move(this->velocity);
    this->padRect.move(this->velocity);
    this->isPaddleMoving = false;
  }
}

void
Paddle::draw(sf::RenderWindow& window)
{
  // window.draw(this->sprite);
  window.draw(this->padRect);
}

void
Paddle::moveUp() noexcept
{
  // do nothing
}

void
Paddle::moveLeft() noexcept
{
  this->velocity.x = -(constants::paddle_speed);
}

void
Paddle::moveRight() noexcept
{
  this->velocity.x = constants::paddle_speed;
}


// respond to user input via key press
void
Paddle::processPlayerInput()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
  {
    if (this->getX() >= 0 && this->isPaddleMoving == false)
    {
      this->velocity.x = -(constants::paddle_speed);
      this->isPaddleMoving = true;
    }
    else
    {
      this->velocity.x = 0;
    }
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
  {
    if (this->getX() <= constants::window_width && this->isPaddleMoving == false)
    {
      this->velocity.x = constants::paddle_speed;
      this->isPaddleMoving = true;
    }
    else
    {
      this->velocity.x = 0;
    }
  }
}