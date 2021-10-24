#pragma once
#include <SDL_rect.h>

#include "Position.h"

//##############################
//DEFINITIONS
//##############################
typedef Rectangle Viewport;

//##############################
//FUNCTIONS
//##############################
SDL_Rect GetViewportSDLRect(const Viewport* _viewport);