#ifndef _ILIST_H_
#define _ILIST_H_

#include <stddef.h>
#include <stdlib.h> 
#include <string.h>
#include "lib/core/basis.h"

/*   IList Interface   */
typedef struct _IList IList;

struct _IList
{
    void (*push)(IList *, int );
    int (*pop)(IList *);
	int (*empty)(IList *);
	size_t (*count)(IList *);
};


#endif // !_ILIST_H_