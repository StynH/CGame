#include "Entity.h"

void InitializeEntityData()
{
	for(uint16_t i = 0; i < MAX_ENTITIES; ++i)
	{
		game_entities.ids[i] = UNUSED_ENTITY_ID;
	}
}

uint16_t GetFreeEntityPosition()
{
	for(uint16_t i = 0; i< MAX_ENTITIES; ++i)
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
	const uint16_t free_entity_position = GetFreeEntityPosition();
	if(free_entity_position != MAX_ENTITIES)
	{
		game_entities.ids[free_entity_position] = free_entity_position;
		game_entities.amount_of_entities++;
		return free_entity_position;
	}

	return -1;
}

void EntitySetSprite(EntityID _entityId, Sprite* _sprite)
{
	game_entities.sprites[_entityId] = _sprite;
}

void EntitySetVelocity(EntityID _entityId, float _velX, float _velY)
{
	game_entities.velocities[_entityId].x = _velX;
	game_entities.velocities[_entityId].y = _velY;
}

void EntitySetRotation(EntityID _entityId, float _angle, float _increase)
{
	game_entities.rotations[_entityId].angle = _angle;
	game_entities.rotations[_entityId].increase = _increase;
}

void FreeEntity(const EntityID _entityId)
{
	game_entities.ids[_entityId] = UNUSED_ENTITY_ID;

	free(game_entities.sprites[_entityId]);

	game_entities.amount_of_entities--;
}
