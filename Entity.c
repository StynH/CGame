#include "Entity.h"

void InitializeEntityData()
{
	for(int i = 0; i < MAX_ENTITIES; ++i)
	{
		game_entities.ids[i] = UNUSED_ENTITY_ID;
	}
}

int GetFreeEntityPosition()
{
	for(int i = 0; i< MAX_ENTITIES; ++i)
	{
		if(game_entities.ids[i] == UNUSED_ENTITY_ID)
		{
			return i;
		}
	}

	return MAX_ENTITIES;
}

EntityID RegisterEntity()
{
	const int free_entity_position = GetFreeEntityPosition();
	if(free_entity_position != MAX_ENTITIES)
	{
		game_entities.ids[free_entity_position] = free_entity_position;
		return free_entity_position;
	}

	return -1;
}

void FreeEntity(const EntityID _entityId)
{
	game_entities.ids[_entityId] = UNUSED_ENTITY_ID;
}