#include "Screen.h"
#include <SDL.h>
#include "Game.h"

void InitializeSDL(const ScreenDimensions _screenDimensions)
{
	SDL_Init(SDL_INIT_VIDEO);

    game_state->window = SDL_CreateWindow(
        "Surge of Power",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        _screenDimensions.x,
        _screenDimensions.y,
        0
    );

    game_state->renderer = SDL_CreateRenderer(game_state->window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawBlendMode(game_state->renderer, SDL_BLENDMODE_BLEND);
}

void SetRenderColor(const Color _rgb, const unsigned char _alpha)
{
    SDL_SetRenderDrawColor(game_state->renderer, _rgb.x, _rgb.y, _rgb.z, _alpha);
}

void ClearScreen()
{
    SDL_RenderClear(game_state->renderer);
}

void PrepareScreen()
{
    Color clearColor;
    clearColor.x = 0;
    clearColor.y = 0;
    clearColor.z = 0;

    SetRenderColor(clearColor, SDL_ALPHA_OPAQUE);
    ClearScreen();
}

void DrawScreen()
{
    SDL_RenderPresent(game_state->renderer);
}

void DestroyScreen()
{
    SDL_DestroyWindow(game_state->window);
    SDL_Quit();
}
