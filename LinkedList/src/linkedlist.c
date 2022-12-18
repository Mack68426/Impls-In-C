#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "ilist.h"
#include "linkedlist.h"

// $Node  = Node_construct;
// $XNode = Node_destruct;
static void LinkedList_push(IList *, int);
static int LinkedList_pop(IList *);
static short LinkedList_empty(IList *);
static size_t LinkList_count(IList *);
// static IIterator* LinkedList_iterator(IList*);


LinkedList *LinkedList_construct(void *addr)
{
    if(!addr) return NULL;
    LinkedList *linkedList = addr;
    
    /* 成員函數綁定 */
    linkedList->push = LinkedList_push;
    linkedList->pop = LinkedList_pop;
    linkedList->empty = LinkedList_empty;
    linkedList->count = LinkedList_count;


    return linkedList;

}
void LinkedList_destruct(LinkedList *self) { self = NULL; }


LinkedList *$LinkedList(void *addr)
{
    // allocate(node, sizeof(struct NodeType));

    if (!addr) return NULL;
    LinkedList *node = addr;
    

    return node;
}

void $XLinkedList(LinkedList *self) { self = NULL; }


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
    LinkedList *llist = container_of(self, LinkedList, ilist)
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