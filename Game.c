#include "Game.h"
#include "Input.h"

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
	PollInput();

	if(window_events.closeButtonClicked)
	{
		game_state->isRunning = false;
	}
}

void DestroyGame()
{
	free(game_state);
}
