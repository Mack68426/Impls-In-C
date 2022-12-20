#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <stdio.h>
#include <stddef.h>


#include "types.h"


typedef struct _Object Object;

/*   Object Interface   */
struct _Object
{
    int (*equals)(Object*, Object*);
    void (*collect)(Object*);
    Object* (*duplicate)(Object*);
    DataType (*getType)(Object*);
};

#endif /* _OBJECT_H_ */