#pragma once
#include "TypeDef.h"

//##############################
//STRUCTS
//##############################
typedef struct DrawableScreen
{
	funcPtrVoid_t init;
	funcPtrVoid_t update;
	funcPtrVoid_t draw;
	funcPtrVoid_t destroy;
} DrawableScreen;