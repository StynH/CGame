#pragma once
#include "TypeDef.h"
#include <stdbool.h>
#include <stdint.h>

//##############################
//STRUCTS
//##############################
typedef struct StackNode
{
	voidPtrConst_t value;
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
voidPtr_t StackPop(Stack* _stack);
void StackPush(Stack* _stack, voidPtrConst_t _value);
voidPtr_t StackFront(const Stack* _stack);
void StackDestroy(const Stack* _stack);