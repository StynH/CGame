#include "Queue.h"

void QueueInitialize(Queue* _queue)
{
	StackInitialize(&_queue->first);
	StackInitialize(&_queue->second);
	_queue->size = 0;
}

bool QueueEmpty(const Queue* _queue)
{
	return StackEmpty(&_queue->first) && StackEmpty(&_queue->second);
}

voidPtr_t QueueDequeue(Queue* _queue)
{
	if(QueueEmpty(_queue)) return NULL;

	if(StackEmpty(&_queue->second))
	{
		while(!StackEmpty(&_queue->first))
		{
			StackPush(&_queue->second, StackPop(&_queue->first));
		}
	}

	_queue->size--;
	return StackPop(&_queue->second);
}

void QueueEnqueue(Queue* _queue, voidPtr_t _value)
{
	StackPush(&_queue->first, _value);
	_queue->size = _queue->first.size + _queue->second.size;
}

void QueueDestroy(const Queue* _queue)
{
	StackDestroy(&_queue->first);
	StackDestroy(&_queue->second);
}
