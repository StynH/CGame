#pragma once
#include <SDL_render.h>
#include <stdbool.h>

#include "Position.h"
#include "Viewport.h"

//##############################
//DEFINITIONS
//##############################
#define ASSET_DIRECTORY "assets"
#define SPRITE_DIRECTORY "/sprites/"

typedef Vector2D Dimensions;
typedef Vector2Df Position;

//##############################
//STRUCTS
//##############################
typedef struct Texture
{
	SDL_Texture* sdl_texture;
	Dimensions dimensions;
} Texture;

typedef struct Sprite
{
	Texture* texture;
	Position position;
	SDL_RendererFlip flip;
} Sprite;

//##############################
//FUNCTIONS
//##############################
Sprite* LoadSprite(const char* _fileName);
Texture* LoadTextureFromDisk(const char* _fileName);
SDL_Rect GetSpriteSourceSDLRect(const Sprite* _sprite);
SDL_Rect GetSpriteDestinationSDLRect(const Sprite* _sprite, const Viewport* _viewport);
void FlipSprite(Sprite* _sprite, bool _vertical, bool _horizontal);