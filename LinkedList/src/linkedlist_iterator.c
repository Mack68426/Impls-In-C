#include <stdio.h>

#include "basis.h"
#include "iiterator.h"
#include "linkedlist_iterator.h"
#include "linkedlist.h"

static int LinkedListIterator_hasNext(IIterator*);
static int LinkedListIterator_next(IIterator*);

LinkedListIterator* LinkedListIterator_construct(void* addr, ListNode* node)
{
	if (addr == NULL)
	{
		return NULL;
	}

	LinkedListIterator* linkedListIterator = addr;
	linkedListIterator->currentNode = node;

	linkedListIterator->hasNext = LinkedListIterator_hasNext;
	linkedListIterator->next = LinkedListIterator_next;

	return linkedListIterator;
}

void LinkedListIterator_destruct(LinkedListIterator* self)
{
}


LinkedListIterator* $LinkedListIterator(void* addr, ListNode* node)
{
	if (!addr) return NULL;

	LinkedListIterator* linkedListIterator = addr;
	linkedListIterator->currentNode = node;

	linkedListIterator->hasNext = LinkedListIterator_hasNext;
	linkedListIterator->next = LinkedListIterator_next;

	return linkedListIterator;
}
void $XLinkedListIterator(IIterator* self)
{	
	LinkedListIterator* linkedListIterator = 
		container_of(self, LinkedListIterator, iiterator);

	delete(LinkedListIterator, linkedListIterator);
}

int LinkedListIterator_hasNext(IIterator* self)
{
	LinkedListIterator* linkedListIterator =
	    container_of(self, LinkedListIterator, iiterator);
	
    return linkedListIterator->currentNode != NULL;
}

int LinkedListIterator_next(IIterator* self)
{
	LinkedListIterator* linkedListIterator =
	    container_of(self, LinkedListIterator, iiterator);
	
    int value = linkedListIterator->currentNode->value;
	linkedListIterator->currentNode = linkedListIterator->currentNode->next;
	
    
    return value;
}
