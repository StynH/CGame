#pragma once
#include "Position.h"
#include "Texture.h"

//##############################
//DEFINITIONS
//##############################
#define MAX_ENTITIES 65536
#define UNUSED_ENTITY_ID 65536

//##############################
//STRUCTS
//##############################
typedef uint32_t EntityID;

typedef struct Entities
{
	EntityID ids[MAX_ENTITIES];
	Vector2Df positions[MAX_ENTITIES];
	Sprite* sprites[MAX_ENTITIES];
} Entities;

Entities game_entities;

//##############################
//FUNCTIONS
//##############################
void InitializeEntityData(void);
int GetFreeEntityPosition(void);
EntityID RegisterEntity(void);
void AddSprite(EntityID _entityId, Sprite* _sprite);
void FreeEntity(EntityID _entityId);