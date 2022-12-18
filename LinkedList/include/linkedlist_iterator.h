#include "iiterator.h"
#include "LinkedList/include/linkedlist.h"

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
