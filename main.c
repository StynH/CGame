#include <stdlib.h>
#include <time.h>
#include "DeltaTime.h"
#include "SDL.h"
#include "Entity.h"
#include "Game.h"
#include "Random.h"
#include "Screen.h"

int main()
{
    srand((unsigned)time(NULL));
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
    InitializeDeltaTime();
    InitializeEntityData();

    //TEST
    for(uint16_t i = 0; i < 100; ++i)
    {
        Sprite* testSprite = LoadSprite("still.png");
        const EntityID entityId = RegisterEntity();
        EntitySetSprite(entityId, testSprite);
        EntitySetRotation(entityId, 0.f, RandomFloatBetween(5.f, 250.f));
        EntitySetVelocity(entityId, RandomFloatBetween(25.f, 150.f), RandomFloatBetween(25.f, 150.f));
    }
    //TEST

    game_state->viewport = viewport;
    while(game_state->isRunning)
    {
        PrepareScreen();
        Update();
        DrawScreen();
    }

    DestroyDeltaTime();
    DestroyScreen();
    DestroyGame();
    DestroyTextures();

    return 0;
}
