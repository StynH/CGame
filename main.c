#include "SDL.h"
#include "Entity.h"
#include "Game.h"
#include "Screen.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main()
{
    InitializeGameState();

    ScreenDimensions dimensions;
    dimensions.x = SCREEN_WIDTH;
    dimensions.y = SCREEN_HEIGHT;
	InitializeSDL(dimensions);

    InitializeEntityData();

    while(game_state->isRunning)
    {
        PrepareScreen();
        Update();
        DrawScreen();
    }

    DestroyScreen();
    DestroyGame();

    return 0;
}
