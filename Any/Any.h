#ifndef ANY_H
#define ANY_H
#include <stddef.h>
#include <stdlib.h>
#include <uchar.h>

#include "lib/core/basis.h"

typedef struct _Generic Generic;


struct _Generic
{
    union
    {
        char __objchr__;
        short;
        int;
        long long;
        Generic* value;
    };
    
};

extern Generic* Generic_construct(Generic )

#endif