#pragma once
#include "Position.h"
#include "Texture.h"
//##############################
//FUNCTIONS
//##############################
void VelocitySystem(Vector2Df* _position, const Vector2Df* _velocity);
void DrawSystem(const Vector2Df* _position, const Rotation* _rotation, Sprite* _sprite);
void RotationSystem(Rotation* _rotation);
void CollisionSystem(Vector2Df* _position, Vector2Df* _velocity);