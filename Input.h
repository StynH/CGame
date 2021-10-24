#pragma once
#include <stdbool.h>

//##############################
//STRUCTS
//##############################
typedef struct WindowEvents
{
	bool closeButtonClicked;
} WindowEvents;

//##############################
//FUNCTIONS
//##############################
void PollInput(void);

//##############################
//GLOBALS
//##############################
WindowEvents window_events;