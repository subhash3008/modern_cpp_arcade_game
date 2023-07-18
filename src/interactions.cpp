#include "../include/interactions.h"
#include <iostream>

bool
isInteracting(const Entity& e1, const Entity& e2)
{
  auto box1 = e1.getBoundingBox();
  auto box2 = e2.getBoundingBox();

  if (box1.intersects(box2))
  {
    std::cout << "Intersected.....   ";
    std::cout << box1.intersects(box2) << std::endl;
  }
  else
  {
    std::cout << "No intersection." << std::endl;
  }

  return box1.intersects(box2);
  
}

void
handleCollision(Ball& b, const Paddle& p)
{
  if (isInteracting(b, p))
  {
    b.moveUp();

    if (b.getX() < p.getX())
      b.moveLeft();
    else
      b.moveRight();
  }
}