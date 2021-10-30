#include "List.h"
#include <stdlib.h>

void ListInitialize(List* _list)
{
	_list->head = NULL;
	_list->size = 0;
}

void ListAdd(List* _list, voidPtr_t _value)
{
	ListNode* head = _list->head;
	while(head && head->next)
	{
		head = head->next;
	}

	ListNode* listNode = malloc(sizeof(ListNode));
	if(listNode)
	{
		listNode->next = NULL;
		listNode->value = _value;

		if(!head)
		{
			_list->head = listNode;
		}
		else 
		{
			head->next = listNode;
		}

		_list->size++;
	}
}

voidPtr_t ListGet(const List* _list, uint32_t _index)
{
	uint32_t index = 0;
	ListNode* node = _list->head;

	while(node && index < _list->size)
	{
		if(index == _index)
		{
			return node->value;
		}

		node = node->next;
		++index;
	}

	return NULL;
}

voidPtr_t ListRemove(List* _list, uint32_t _index)
{
	uint32_t index = 0;
	ListNode* node = _list->head;
	ListNode* prevNode = NULL;

	while (node && index < _list->size)
	{
		if (index == _index)
		{
			voidPtr_t value = node->value;
			if(prevNode)
			{
				prevNode->next = node->next;
			}
			else
			{
				_list->head = node->next;
			}
			_list->size--;

			free(node);
			return value;
		}

		prevNode = node;
		node = node->next;
		++index;
	}

	return NULL;
}
