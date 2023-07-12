#include "include/creature.h"

// static initialization
mt19937 Creature::mt;
bernoulli_distribution Creature::bd;


// constructor
Creature::Creature(float x, float y)
{
  // set x and y as initial position
  this->velocity = { vx, vy };
  this->circle.setPosition(x, y);

  // set graphical properties of the creature
  circle.setRadius(10.0f);
  circle.setFillColor(sf::Color::Cyan);
}


// function to draw the creature on the render buffer
void
Creature::draw(sf::RenderWindow& window)
{
  window.draw(this->circle);
}

// function to update the creature position
void
Creature::update()
{
  this->vx = bd(mt) ? this->vx : -(this->vx);
  this->vy = bd(mt) ? this->vy : -(this->vy);
  
  // move the creature to new position
  this->circle.move({ this->vx, this->vx });
}