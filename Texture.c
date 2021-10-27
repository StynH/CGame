#include "Texture.h"
#include "SDL_image.h"
#include "Game.h"
#include "String.h"

Sprite* LoadSprite(const char* _fileName)
{
	if(texture_hashmap == NULL)
	{
		InitializeTextureHashMap();
	}

	Texture* texture = GetTextureFromHashMap(_fileName);
	if(texture == NULL)
	{
		texture = LoadTextureFromDisk(_fileName);
		AddTextureToHashMap(_fileName, texture);
	}

	Sprite* sprite = malloc(sizeof(Sprite));
	if(sprite)
	{
		sprite->texture = texture;
		sprite->position.x = 0.f;
		sprite->position.y = 0.f;
		
		sprite->center.x = (float)texture->dimensions.x / 2.f;
		sprite->center.y = (float)texture->dimensions.y / 2.f;

		sprite->rotation_angle = 0.f;

		sprite->flip = SDL_FLIP_NONE;

		return sprite;
	}

	return NULL;
}

Texture* LoadTextureFromDisk(const char* _fileName)
{
	const char* fullDir = StringAppend(StringAppend(ASSET_DIRECTORY, SPRITE_DIRECTORY), _fileName);
	SDL_Surface* tempSurface = IMG_Load(fullDir);
	SDL_Texture* SDLTexture = SDL_CreateTextureFromSurface(game_state->renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	Dimensions dimensions;
	SDL_QueryTexture(SDLTexture, NULL, NULL, &dimensions.x, &dimensions.y);

	Texture* texture = malloc(sizeof(Texture));
	if(texture)
	{
		texture->sdl_texture = SDLTexture;
		texture->dimensions = dimensions;
		return texture;
	}

	return NULL;
}

SDL_Rect SpriteGetSourceSDLRect(const Sprite* _sprite)
{
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = _sprite->texture->dimensions.x;
	rect.h = _sprite->texture->dimensions.y;
	return rect;
}

SDL_Rect SpriteGetDestinationSDLRect(const Sprite* _sprite, const Viewport* _viewport)
{
	SDL_Rect rect;
	rect.x = (int32_t)(_sprite->position.x - (float)_viewport->x);
	rect.y = (int32_t)(_sprite->position.y - (float)_viewport->y);
	rect.w = _sprite->texture->dimensions.x;
	rect.h = _sprite->texture->dimensions.y;
	return rect;
}

SDL_Point SpriteGetCenter(const Sprite* _sprite)
{
	SDL_Point point;
	point.x = (int32_t)_sprite->center.x;
	point.y = (int32_t)_sprite->center.y;
	return point;
}

void FlipSprite(Sprite* _sprite, bool _vertical, bool _horizontal)
{
	if(_vertical)
	{
		_sprite->flip ^= SDL_FLIP_VERTICAL;
	}

	if(_horizontal)
	{
		_sprite->flip ^= SDL_FLIP_HORIZONTAL;
	}
}

void DestroyTextures()
{
	HashMapDestroy(texture_hashmap);
}

void InitializeTextureHashMap()
{
	texture_hashmap = malloc(sizeof(HashMap));
	HashMapInitialize(texture_hashmap);
}

void AddTextureToHashMap(const char* _fileName, Texture* _texture)
{
	HashMapAdd(texture_hashmap, _fileName, _texture);
}

Texture* GetTextureFromHashMap(const char* _fileName)
{
	return HashMapGet(texture_hashmap, _fileName);
}
