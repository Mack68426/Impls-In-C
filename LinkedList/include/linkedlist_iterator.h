#include <stdio.h>
#include "iiterator.h"
#include "linkedlist.h"

typedef struct _LinkedListIterator LinkedListIterator;

struct _LinkedListIterator
{
	ListNode* currentNode;

	union
	{
		IIterator;
		IIterator iiterator;
	};
};

extern LinkedListIterator* LinkedListIterator_construct(void*, ListNode*);
extern void LinkedListIterator_destruct(LinkedListIterator*);
extern LinkedListIterator* $LinkedListIterator(void*, ListNode*);
extern void $XLinkedListIterator(IIterator*);