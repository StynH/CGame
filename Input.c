#include "Input.h"
#include <SDL_events.h>

void PollInput()
{
	SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
	        case SDL_QUIT:
				window_events.closeButtonClicked = true;
	            break;
			default: break;
        }
    }
}
