#ifndef GENERAL_H
#define GENERAL_H

#include <stdio.h>
#include <stddef.h>

#include "types.h"
#include "object.h"

#define GENERAL_FORMAT "%$"

typedef struct _General General;
typedef union _Primitive Primitive;


struct _General
{
    DataType type;
    int (*compare)(void *, void *);

    union _Primitive
    {
        char        ;
        short       ;
        int         ;
        long        ;
        float       ;
        double      ;
        long double ;
        // char        ch;
        // short       sh;
        // int          i;
        // long         l;
        // float        f;
        // double       d;
        // long double ld;

    } value;

    union
    {
        Object;
        Object iobj;
    };
};

extern General* General_construct(void*);
extern void General_destruct(General*);
extern void General_printf(const char* , ...);

#endif