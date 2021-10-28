#pragma once
#include <stdbool.h>
#include <stdint.h>
//##############################
//STRUCTS
//##############################
typedef struct StackNode
{
	void* value;
	struct StackNode* next;
} StackNode;

typedef struct Stack
{
	StackNode* head;
	uint32_t size;
} Stack;

//##############################
//FUNCTIONS
//##############################
void StackInitialize(Stack* _stack);
bool StackEmpty(const Stack* _stack);
void* StackPop(Stack* _stack);
void StackPush(Stack* _stack, void* _value);
void* StackFront(const Stack* _stack);