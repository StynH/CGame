#include "DeltaTime.h"
#include <stdlib.h>

void InitializeDeltaTime() {
    timer = malloc(sizeof(DeltaTime));
    if(timer)
    {
        timer->now = SDL_GetPerformanceCounter();
        timer->deltaTime = 0.f;
    }
}

void TickDeltaTime() {
    timer->last = timer->now;
    timer->now = SDL_GetPerformanceCounter();

    timer->deltaTime = (
        (timer->now - timer->last) * 1000.f /
        (float)(SDL_GetPerformanceFrequency())
    ) / 1000.f;
}

void FreeTime() {
    free(timer);
}