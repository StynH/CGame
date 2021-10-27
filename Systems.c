#include "Systems.h"
#include "DeltaTime.h"
#include "Screen.h"

void VelocitySystem(Vector2Df* _position, const Vector2Df* _velocity)
{
	if (_velocity == NULL || _position == NULL) return;
	_position->x += _velocity->x * timer->deltaTime;
	_position->y += _velocity->y * timer->deltaTime;
}

void DrawSystem(const Vector2Df* _position, const Rotation* _rotation, Sprite* _sprite)
{
	if (_sprite == NULL || _position == NULL) return;
	_sprite->position.x = _position->x;
	_sprite->position.y = _position->y;
	_sprite->rotation_angle = _rotation->angle;

	DrawSprite(_sprite);
}

void RotationSystem(Rotation* _rotation)
{
	if (_rotation == NULL) return;
	_rotation->angle += _rotation->increase * timer->deltaTime;
	if (_rotation->angle > 360.f || _rotation->angle < -360.f)
	{
		_rotation->angle = 0;
	}
}

//Test implementation
void CollisionSystem(Vector2Df* _position, Vector2Df* _velocity)
{
	if (_velocity == NULL || _position == NULL) return;
	if(_position->x + (_velocity->x * timer->deltaTime) > SCREEN_WIDTH - 25 || _position->x + (_velocity->x * timer->deltaTime) < 0)
	{
		_velocity->x = -_velocity->x;
	}

	if (_position->y + (_velocity->y * timer->deltaTime) > SCREEN_HEIGHT - 49 || _position->y + (_velocity->y * timer->deltaTime) < 0)
	{
		_velocity->y = -_velocity->y;
	}
}

