#include "TestScreen.h"
#include <stdlib.h>
#include "Entity.h"
#include "Systems.h"

DrawableScreen* CreateTestScreen()
{
	DrawableScreen* screen = malloc(sizeof(DrawableScreen));
	if(screen)
	{
		screen->init = TestScreenInit;
		screen->draw = TestScreenDraw;
		screen->update = TestScreenUpdate;
		screen->destroy = TestScreenDestroy;
	}
	return screen;
}

void TestScreenInit()
{
	//UNUSED
}

void TestScreenUpdate()
{
	uint32_t index = 0;
	uint32_t entitiesUpdated = 0;
	while (entitiesUpdated < game_entities.amount_of_entities && index < MAX_ENTITIES)
	{
		if (game_entities.ids[index] != UNUSED_ENTITY_ID)
		{
			CollisionSystem(&game_entities.positions[index], &game_entities.velocities[index]);
			VelocitySystem(&game_entities.positions[index], &game_entities.velocities[index]);
			RotationSystem(&game_entities.rotations[index]);
			DrawSystem(&game_entities.positions[index], &game_entities.rotations[index], game_entities.sprites[index]);
			++entitiesUpdated;
		}
		++index;
	}
}

void TestScreenDraw()
{
	//UNUSED
}

void TestScreenDestroy()
{
	//UNUSED
}
