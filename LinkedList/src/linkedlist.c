#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "basis.h"
#include "ilist.h"
#include "iiterator.h"
#include "linkedlist.h"
#include "linkedlist_iterator.h"


static void LinkedList_push(IList *, int);
static int LinkedList_pop(IList *);
static short LinkedList_empty(IList *);
static size_t LinkedList_count(IList *);
static IIterator* LinkedList_iterator(IList*);


LinkedList *LinkedList_construct(void *addr)
{
    if(!addr) return NULL;
    LinkedList *linkedList = addr;
    linkedList->Head = NULL;
    
    /* 成員函數綁定 */
    linkedList->push = LinkedList_push;
    linkedList->pop = LinkedList_pop;
    linkedList->empty = LinkedList_empty;
    linkedList->count = LinkedList_count;
    linkedList->iterator = LinkedList_iterator;

    return linkedList;

}
void LinkedList_destruct(LinkedList *self)
{

}


LinkedList *$LinkedList(void *addr)
{
    if(!addr) return NULL;

    LinkedList *linkedList = addr;
    linkedList->Head = NULL;
    
    /* 成員函數綁定 */
    linkedList->push = LinkedList_push;
    linkedList->pop = LinkedList_pop;
    linkedList->empty = LinkedList_empty;
    linkedList->count = LinkedList_count;
    linkedList->iterator = LinkedList_iterator;

    return linkedList;
}

void $XLinkedList(IList *self)
{
    LinkedList* linkedList = 
        container_of(self, LinkedList, ilist);
    
    delete(LinkedList, linkedList);

}


void LinkedList_push(IList *self, int element)
{
    LinkedList *llist = container_of(self, LinkedList, ilist);
    
    ListNode **node = &llist->Head;

    while (*node != NULL) node = &(*node)->next;

    ListNode *tmpNode = (ListNode *)malloc(sizeof(ListNode));
    tmpNode->value = element;
    tmpNode->next = NULL;

    *node = tmpNode;

}

int LinkedList_pop(IList * self)
{
    LinkedList *llist = container_of(self, LinkedList, ilist);
    assert(llist->Head != NULL);

    ListNode *tmp = llist->Head;
    llist->Head = tmp->next;

    int value = tmp->value;

    free(tmp);

    return value;
}


short LinkedList_empty(IList *self)
{
    LinkedList *linkedList = container_of(self, LinkedList, ilist);

    return linkedList->Head == NULL;
}

size_t LinkedList_count(IList *self)
{
    LinkedList *linkedList = container_of(self, LinkedList, ilist);

    ListNode *tmp = linkedList->Head;

    size_t count = 0;
    for (; tmp; tmp = tmp->next)    ++count;

    return count;
}


IIterator* LinkedList_iterator(IList* self)
{
    LinkedList* linkedList = container_of(self, LinkedList, ilist);
    
	return &new(LinkedListIterator, linkedList->Head)->iiterator;
}
