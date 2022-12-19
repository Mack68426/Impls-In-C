#ifndef _ILIST_H_
#define _ILIST_H_

#include <stdio.h>
#include <stddef.h>
#include "iiterator.h"

/*   IList Interface   */
typedef struct _IList IList;

struct _IList
{
    void (*push)(IList *, int );
    int (*pop)(IList *);
	short (*empty)(IList *);
	size_t (*count)(IList *);
    IIterator* (*iterator)(IList *);
};


#endif // !_ILIST_H_