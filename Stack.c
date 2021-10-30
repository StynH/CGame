#include "Stack.h"
#include <stdlib.h>

void StackInitialize(Stack* _stack)
{
	_stack->head = NULL;
	_stack->size = 0;
}

bool StackEmpty(const Stack* _stack)
{
	return _stack->size == 0;
}

voidPtr_t StackPop(Stack* _stack)
{
	if (StackEmpty(_stack)) return NULL;

	StackNode* front = _stack->head;
	const voidPtrConst_t frontVal = front->value;

	_stack->head = front->next;
	_stack->size--;

	free(front);

	return frontVal;
}

void StackPush(Stack* _stack, voidPtrConst_t _value)
{
	StackNode* node = malloc(sizeof(StackNode));
	if(node)
	{
		node->value = _value;
		node->next = _stack->head;

		_stack->head = node;
		_stack->size++;
	}
}

voidPtr_t StackFront(const Stack* _stack)
{
	return _stack->head->value;
}

void StackDestroy(const Stack* _stack)
{
	StackNode* node = _stack->head;
	while(node)
	{
		StackNode* next = node->next;
		free(node);
		node = next;
	}
}
