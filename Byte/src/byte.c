#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "basis.h"
#include "byte.h"

// 8-bit data
struct _nbits
{
    ubyte :1;
    ubyte :1;
    ubyte :1;
    ubyte :1;
    ubyte :1;
    ubyte :1;
    ubyte :1;
    ubyte :1;
} ;

#if defined(INNER_BITS_TYPE_IMPL)

struct __bits
{
    ubyte b0:1;
    ubyte b1:1;
    ubyte b2:1;
    ubyte b3:1;
    ubyte b4:1;
    ubyte b5:1;
    ubyte b6:1;
    ubyte b7:1;
};

extern _bits_t __bits_field__;

#define type(o) typeof(o)
// typedef type(__bit_fields__) bit_t;

#endif


static Byte* Byte_AND();



void test()
{
    _byte_t bite = (_byte_t){.__data__ = 8};

    
    
    printf("\n%d\n", bite.__data__);

    // printf("%d %d %d %d %d %d %d %d\n",
    //     bite.b0, bite.b1, bite.b2, bite.b3, bite.b4, bite.b5, bite.b6, bite.b7);

    printf("\n");


}