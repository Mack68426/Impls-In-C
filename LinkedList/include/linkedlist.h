#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "lib/core/basis.h"
#include "ilist.h"

typedef struct _ListNode ListNode;
typedef struct _LinkedList LinkedList;

struct _ListNode
{
    int value;
    ListNode *next;
};

struct _LinkedList
{
    ListNode *Head;

    union
	{
		IList;
		IList ilist;
	};
};

extern LinkedList *LinkedList_construct(void *);
extern void LinkedList_destruct(IList *);
extern LinkedList *$LinkedList(void *);
extern void $XList(LinkedList *);


#endif // !_LINKEDLIST_H_