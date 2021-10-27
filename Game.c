#include "Game.h"
#include "DeltaTime.h"
#include "Entity.h"
#include "Input.h"
#include "Systems.h"

void InitializeGameState()
{
	game_state = malloc(sizeof(GameState));
	if(game_state)
	{
		game_state->isRunning = true;
	}
}

void Update()
{
	TickDeltaTime();
	PollInput();
	UpdateSystems();

	if(window_events.closeButtonClicked)
	{
		game_state->isRunning = false;
	}
}

void DestroyGame()
{
	free(game_state);
}

void UpdateSystems()
{
	uint32_t index = 0;
	uint32_t entitiesUpdated = 0;
	while(entitiesUpdated < game_entities.amount_of_entities && index < MAX_ENTITIES)
	{
		if(game_entities.ids[index] != UNUSED_ENTITY_ID)
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
