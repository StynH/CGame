#pragma once
#include "Position.h"

//##############################
//DEFINITIONS
//##############################
#define MAX_ENTITIES 65536
#define UNUSED_ENTITY_ID 65536

//##############################
//STRUCTS
//##############################
typedef unsigned int EntityID;

typedef struct Entities
{
	EntityID ids[MAX_ENTITIES];
	Vector2Df positions[MAX_ENTITIES];
} Entities;

Entities game_entities;

//##############################
//FUNCTIONS
//##############################
void InitializeEntityData(void);
int GetFreeEntityPosition(void);
EntityID RegisterEntity(void);
void FreeEntity(EntityID _entityId);