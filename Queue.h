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
voidPtr_t QueueDequeue(Queue* _queue);
void QueueEnqueue(Queue* _queue, voidPtr_t _value);
void QueueDestroy(const Queue* _queue);