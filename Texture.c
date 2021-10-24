#include "Texture.h"
#include "SDL_image.h"
#include "Game.h"
#include "String.h"

Sprite* LoadSprite(const char* _fileName)
{
	Texture* texture = LoadTextureFromDisk(_fileName);

	Sprite* sprite = malloc(sizeof(Sprite*));
	if(sprite)
	{
		sprite->texture = texture;
		sprite->position.x = 0.f;
		sprite->position.y = 0.f;
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

SDL_Rect GetSpriteSourceSDLRect(const Sprite* _sprite)
{
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = _sprite->texture->dimensions.x;
	rect.h = _sprite->texture->dimensions.y;
	return rect;
}

SDL_Rect GetSpriteDestinationSDLRect(const Sprite* _sprite, const Viewport* _viewport)
{
	SDL_Rect rect;
	rect.x = (int)(_sprite->position.x - (float)_viewport->x);
	rect.y = (int)(_sprite->position.y - (float)_viewport->y);
	rect.w = _sprite->texture->dimensions.x;
	rect.h = _sprite->texture->dimensions.y;
	return rect;
}

void FlipSprite(Sprite* _sprite, bool _vertical, bool _horizontal)
{
	if(_vertical)
	{
		_sprite->flip = _sprite->flip == SDL_FLIP_NONE ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE;
	}
	else if(_horizontal)
	{
		_sprite->flip = _sprite->flip == SDL_FLIP_NONE ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
	}
	else if (_vertical && _horizontal)
	{
		_sprite->flip = _sprite->flip == SDL_FLIP_NONE ? SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL : SDL_FLIP_NONE;
	}
}
