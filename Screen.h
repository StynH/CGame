#pragma once
#include "Position.h"
#include "Texture.h"
#include "Viewport.h"

//##############################
//DEFINITIONS
//##############################
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef Vector2D ScreenDimensions;
typedef Vector3Du Color;

//##############################
//FUNCTIONS
//##############################
void InitializeSDL(ScreenDimensions _screenDimensions);
void SetRenderColor(Color _rgb, uint8_t _alpha);
void ClearScreen(void);
void PrepareScreen(void);
void SetViewport(const Viewport* _viewport);
void DrawScreen(void);
void DrawSprite(const Sprite* _sprite);
void DestroyScreen(void);