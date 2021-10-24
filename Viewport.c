#include "Viewport.h"

#include <SDL_rect.h>

SDL_Rect GetViewportSDLRect(const Viewport* _viewport)
{
	SDL_Rect rect;
	rect.x = _viewport->x;
	rect.y = _viewport->y;
	rect.h = _viewport->height;
	rect.w = _viewport->width;
	return rect;
}
