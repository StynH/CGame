#pragma once
#include <SDL_timer.h>

//##############################
//STRUCTURES
//##############################
typedef struct {
    uint64_t now;
    uint64_t last;
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