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

  // function to get the bounding rectangle of the sprite
  sf::FloatRect getBoundingBox() const noexcept;

  // function to get the center of the sprite
  sf::Vector2f getCenter() const noexcept;

  // getter functions for position of sprite
  float getX() const noexcept;
  float getY() const noexcept;

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