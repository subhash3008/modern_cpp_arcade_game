#ifndef CREATURE_H
#define CREATURE_H

#include <SFML/Graphics.hpp>
#include <random>

using namespace std;

class Creature
{
private:
  // static number generator and bernoulli distribution objects
  static mt19937 mt;
  static bernoulli_distribution bd;

  // properties of creature
  float vx{ 10.0f };
  float vy{ 10.0f };
  sf::Vector2f velocity;

  // creature is circular in shape
  sf::CircleShape circle;

public:
  // constructor
  Creature(float x, float y);
  
  // function to draw the creature on the buffer
  void draw(sf::RenderWindow& window);

  // compute creature's new position
  void update();
};

#endif // CREATURE_H