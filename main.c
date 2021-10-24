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

    Viewport* viewport = malloc(sizeof(Viewport));
    if(viewport)
    {
        viewport->width = SCREEN_WIDTH;
        viewport->height = SCREEN_HEIGHT;
        viewport->x = 0;
        viewport->y = 0;
    }
	InitializeSDL(dimensions);

    InitializeEntityData();

    //TEST
    const Sprite* testSprite = LoadSprite("icon-user-default.png");
    //TEST

    game_state->viewport = viewport;
    while(game_state->isRunning)
    {
        PrepareScreen();
        Update();

        //TEST
        DrawSprite(testSprite);
        //TEST

        DrawScreen();
    }

    DestroyScreen();
    DestroyGame();

    return 0;
}
