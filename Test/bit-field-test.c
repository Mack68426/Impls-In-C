#include <stdio.h>
#include <stdlib.h>

#include "../lib/core/basis.h"

typedef struct _Assignable Assignable;
typedef struct _Any Any;
typedef enum _Boolean boolean;
// typedef struct _primitive_ pmt;

enum _Boolean { false, true };

struct _Boo
{
    enum { false, true };
    union
    {
        unsigned :1;
        unsigned :1;
        unsigned :1;
        unsigned :1;
        unsigned :1;
        unsigned :1;
        unsigned :1;
        unsigned :1;
    };
};

struct _Assignable
{
    void (*data)(Assignable*);
};

struct _Any 
{
    void *value;

    union
    {
        Assignable;
        Assignable iassi;
    };
    
    union _primitive_
    {
        boolean /* __bool_type__  */ :  1;
        char    /* __char_type__  */ :  8;
        short   /* __short_type__ */ :  8;
        int     /* __int_type__   */ : 32;
        long    /* __long_type__  */ : 32;
        double  /* __double_type__ */: 64;

    };
};

void *Any_data(Assignable*);

Any* staff_preprocess(void *addr);


int main()
{
    Any* a  = malloc(sizeof(Any));

    a->value = "Test";

    printf("%d", a->value);

    return 0;
}
Any* staff_preprocess(void *addr)
{
    Any* obj = addr;

    obj->data = Any_data;

    return obj;
    
}


void *Any_data(Assignable* myself)
{
    Any *o = container_of(myself, Any, iassi);

    return o->value;
}