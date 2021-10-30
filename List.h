#pragma once
#include "TypeDef.h"
#include <stdint.h>

//##############################
//STRUCTS
//##############################
typedef struct ListNode
{
	voidPtr_t value;
	struct ListNode* next;
} ListNode;

typedef struct List
{
	ListNode* head;
	uint32_t size;
} List;

//##############################
//FUNCTIONS
//##############################
void ListInitialize(List* _list);
void ListAdd(List* _list, voidPtr_t _value);
voidPtr_t ListGet(const List* _list, uint32_t _index);
voidPtr_t ListRemove(List* _list, uint32_t _index);
