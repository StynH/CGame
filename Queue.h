#pragma once
#include <stdbool.h>
#include <stdint.h>
#include "Stack.h"

//##############################
//STRUCTS
//##############################
typedef struct Queue
{
	Stack first;
	Stack second;
	uint32_t size;
} Queue;

//##############################
//FUNCTIONS
//##############################
void QueueInitialize(Queue* _queue);
bool QueueEmpty(const Queue* _queue);
void* QueueDequeue(Queue* _queue);
void QueueEnqueue(Queue* _queue, void* _value);
void QueueDestroy(const Queue* _queue);