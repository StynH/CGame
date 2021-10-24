#pragma once
#include <SDL_render.h>
#include <SDL_video.h>
#include <stdbool.h>

//##############################
//STRUCTURES
//##############################
typedef struct GameState
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning;
} GameState;

//##############################
//FUNCTIONS
//##############################
void InitializeGameState(void);
void Update(void);
void DestroyGame(void);

//##############################
//GLOBALS
//##############################
GameState* game_state;