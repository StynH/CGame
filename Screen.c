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
    SetViewport(game_state->viewport);
}

void SetViewport(const Viewport* _viewport)
{
	const SDL_Rect rect = GetViewportSDLRect(_viewport);
    SDL_RenderSetViewport(game_state->renderer, &rect);
}

void DrawScreen()
{
    SDL_RenderPresent(game_state->renderer);
}

void DrawSprite(const Sprite* _sprite)
{
	const SDL_Rect dstRect = GetSpriteDestinationSDLRect(_sprite, game_state->viewport);
	const SDL_Rect srcRect = GetSpriteSourceSDLRect(_sprite);
    SDL_RenderCopy(game_state->renderer, _sprite->texture->sdl_texture, &srcRect, &dstRect);
}

void DestroyScreen()
{
    SDL_DestroyWindow(game_state->window);
    SDL_Quit();
}
