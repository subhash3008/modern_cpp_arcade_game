#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

// asbtract class to represent any graphical entity
// on the game screen
class Entity
{
protected:
  sf::Sprite sprite;

public:
  // pure virtual functions
  // graphic entities must update these functions
  virtual void update() = 0;
  virtual void draw(sf::RenderWindow& window) = 0;

  virtual ~Entity() {};
};

// moving entity
class MovingEntity : public Entity
{
protected:
  // sfml vector to store moving entity's velocity
  sf::Vector2f velocity;

public:
  // inherited functions to be implemented
};

#endif // ENTITY_H