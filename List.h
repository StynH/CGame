#pragma once
#include <stdint.h>

//##############################
//STRUCTS
//##############################
typedef struct ListNode
{
	void* value;
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
void ListAdd(List* _list, void* _value);
void* ListGet(const List* _list, uint32_t _index);
void* ListRemove(List* _list, uint32_t _index);