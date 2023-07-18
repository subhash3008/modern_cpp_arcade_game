#ifndef PADDLE_H
#define PADDLE_H

#include "constants.h"
#include "entity.h"
#include "rounded_rectangle.h"

// Paddle stays near bottom of the screen and
// moved horizontally to catch the moving ball.
// when ball hits the paddle, the ball would change
// it's direction
class Paddle : public MovingEntity
{
  static sf::Texture texture;

  static sf::RoundedRectangleShape padRect;

  bool isPaddleMoving = false;

  // respond to input from user keyboard
  void processPlayerInput();

public:
  // constructor to initialize paddle position
  Paddle(float x, float y);

  // implement pure virtual functions
  void update() override;
  void draw(sf::RenderWindow& window) override;

  void moveUp() noexcept override;
  void moveLeft() noexcept override;
  void moveRight() noexcept override;
};

#endif // PADDLE_H