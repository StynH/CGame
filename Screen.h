#pragma once
#include "Position.h"

//##############################
//DEFINITIONS
//##############################
typedef Vector2D ScreenDimensions;
typedef Vector3Du Color;

//##############################
//FUNCTIONS
//##############################
void InitializeSDL(ScreenDimensions _screenDimensions);
void SetRenderColor(Color _rgb, unsigned char _alpha);
void ClearScreen(void);
void PrepareScreen(void);
void DrawScreen(void);
void DestroyScreen(void);