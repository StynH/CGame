#include "Game.h"
#include "DeltaTime.h"
#include "DrawableScreen.h"
#include "Input.h"

void InitializeGameState()
{
	game_state = malloc(sizeof(GameState));
	if(game_state)
	{
		game_state->isRunning = true;
	}

	screen_stack = malloc(sizeof(Stack));
}

void SetScreen(const DrawableScreen* _screen)
{
	StackPush(screen_stack, _screen);
}

void Update()
{
	TickDeltaTime();
	PollInput();
	UpdateCurrentScreen();
	DrawCurrentScreen();

	if(window_events.closeButtonClicked)
	{
		game_state->isRunning = false;
	}
}

void DestroyGame()
{
	free(game_state);
	StackDestroy(screen_stack);
	free(screen_stack);
}

void DrawCurrentScreen()
{
	const DrawableScreen* screen = StackFront(screen_stack);
	screen->draw();
}

void UpdateCurrentScreen()
{
	const DrawableScreen* screen = StackFront(screen_stack);
	screen->update();
}
