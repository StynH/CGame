#pragma once
#include <SDL_timer.h>

//##############################
//STRUCTURES
//##############################
typedef struct {
    Uint64 now;
    Uint64 last;
    float deltaTime;
} DeltaTime;

//##############################
//FUNCTIONS
//##############################
void InitializeDeltaTime(void);
void TickDeltaTime(void);
void DestroyDeltaTime(void);

//##############################
//GLOBALS
//##############################
DeltaTime* timer;