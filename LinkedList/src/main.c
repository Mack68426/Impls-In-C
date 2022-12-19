

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "basis.h"
#include "ilist.h"
#include "iiterator.h"
#include "linkedlist.h"
#include "linkedlist_iterator.h"


int main()
{
    LinkedList* list = new$(LinkedList);

    for (int i=0; i<10; i++)
    {
        list->push(&list->ilist, i);
    }

    IIterator* iterator = list->iterator(&list->ilist);

    while (iterator->hasNext(iterator))
    {
        printf("%d\n", iterator->next(iterator));
    }
    printf("\n");

    // LinkedListIterator* linkedListIterator =
	//     container_of(iterator, LinkedListIterator, iiterator);
    
	// delete (LinkedListIterator, linkedListIterator);
    

    $XLinkedListIterator(iterator);

    
    $XLinkedList(&list->ilist);

    return 0;
}