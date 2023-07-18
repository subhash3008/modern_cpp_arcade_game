#ifndef BALL_H
#define BALL_H

#include "constants.h"
#include "entity.h"

class Ball : public MovingEntity
{
private:
  // texture for ball
  static sf::Texture texture;

public:
  //constructor
  Ball(float x, float y);

  // inherited pure virtual functions
  void update() override;
  void draw(sf::RenderWindow& window) override;

  void moveUp() noexcept override;
  void moveLeft() noexcept override;
  void moveRight() noexcept override;

};

#endif // BALL_H
