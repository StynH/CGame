#pragma once
#include <SDL_render.h>
#include <stdbool.h>
#include "HashMap.h"
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
	Vector2Df center;
	SDL_RendererFlip flip;
	float rotation_angle;
} Sprite;

//##############################
//FUNCTIONS
//##############################
Sprite* LoadSprite(const char* _fileName);
Texture* LoadTextureFromDisk(const char* _fileName);
SDL_Rect SpriteGetSourceSDLRect(const Sprite* _sprite);
SDL_Rect SpriteGetDestinationSDLRect(const Sprite* _sprite, const Viewport* _viewport);
SDL_Point SpriteGetCenter(const Sprite* _sprite);
void FlipSprite(Sprite* _sprite, bool _vertical, bool _horizontal);
void DestroyTextures(void);

//##############################
//PRIVATE
//##############################
HashMap* texture_hashmap;
static void InitializeTextureHashMap(void);
static void AddTextureToHashMap(const char* _fileName, Texture* _texture);
static Texture* GetTextureFromHashMap(const char* _fileName);