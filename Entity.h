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
	Sprite* sprites[MAX_ENTITIES];
} Entities;

//##############################
//FUNCTIONS
//##############################
void InitializeEntityData(void);
uint16_t GetFreeEntityPosition(void);
EntityID RegisterEntity(void);
void AddSprite(EntityID _entityId, Sprite* _sprite);
void FreeEntity(EntityID _entityId);

//##############################
//GLOBALS
//##############################
Entities game_entities;