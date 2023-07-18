#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include "ball.h"
#include "paddle.h"

// check if two entities overlap
bool isInteracting(const Entity& e1, const Entity& e2);

// handle the actions when the ball and the paddle
void handleCollision(Ball& b, const Paddle& p);

#endif // INTERACTIONS_H