#pragma once
#include <SDL_render.h>
#include <SDL_video.h>
#include <stdbool.h>

#include "DrawableScreen.h"
#include "Stack.h"
#include "Viewport.h"

//##############################
//STRUCTURES
//##############################
typedef struct GameState
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	Viewport* viewport;
	bool isRunning;
} GameState;

//##############################
//FUNCTIONS
//##############################
void InitializeGameState(void);
void SetScreen(const DrawableScreen* _screen);
void Update(void);
void DestroyGame(void);

//##############################
//PRIVATE
//##############################
static void DrawCurrentScreen(void);
static void UpdateCurrentScreen(void);

//##############################
//GLOBALS
//##############################
GameState* game_state;
Stack* screen_stack;