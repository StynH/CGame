#pragma once
#include "Position.h"
#include "Texture.h"

//##############################
//DEFINITIONS
//##############################
#define MAX_ENTITIES 65535
#define UNUSED_ENTITY_ID 65535

//##############################
//STRUCTS
//##############################
typedef uint16_t EntityID;

typedef struct Entities
{
	EntityID ids[MAX_ENTITIES];
	Vector2Df positions[MAX_ENTITIES];
	Vector2Df velocities[MAX_ENTITIES];
	Rotation rotations[MAX_ENTITIES];
	Sprite* sprites[MAX_ENTITIES];
	uint32_t amount_of_entities;
} Entities;

//##############################
//FUNCTIONS
//##############################
void InitializeEntityData(void);
uint16_t GetFreeEntityPosition(void);
EntityID RegisterEntity(void);
void EntitySetSprite(EntityID _entityId, Sprite* _sprite);
void EntitySetVelocity(EntityID _entityId, float _velX, float _velY);
void EntitySetRotation(EntityID _entityId, float _angle, float _increase);
void FreeEntity(EntityID _entityId);

//##############################
//GLOBALS
//##############################
Entities game_entities;