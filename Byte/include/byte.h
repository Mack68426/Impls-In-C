#ifndef BYTE_H
#define BYTE_H

#include <stddef.h>
#include <stdbool.h>

#define INNER_BITS_TYPE_IMPL
#define FALSE ((void)0)
#define TRUE  ((void)1)
#define MAX_VALUE  0x7f
#define MIN_VALUE -0x7f

// 原始 byte 型態
typedef unsigned char ubyte_t;
typedef signed char byte_t;

// 包裝器內部的結構型態
typedef struct __bits _bits_t; /// the closed structure ///
typedef struct _nbits nbit_t;  /// the opened structure ///
typedef union __byte _byte_t;  /// the  inner   wrapper ///

// 包裝器型態
typedef struct _Byte Byte;     /// the  true    wrapper ///


#define ubyte ubyte_t
#define byte byte_t

//////////// 測試用 ////////////
// typedef struct _array Array;

/* struct _array
{
    int* data;
    size_t capacity;
    size_t size;
};
 */
///////////////////////////////

union __byte
{
    byte __data__;
    
    nbit_t;
    nbit_t __nbits_field__;
} ;

struct _Byte
{
    _byte_t bValue;
    

    byte  (*get)(Byte*);
    Byte* (*lshift)(Byte*, int);
    Byte* (*rshift)(Byte*, int);
    Byte* (*AND)(Byte*, Byte*);
    Byte* (*OR)(Byte*, Byte*);
    Byte* (*NOT)(Byte*, Byte*);
    Byte* (*XOR)(Byte*, Byte*);
} ;

extern Byte* Byte_construct(void*);
extern void Byte_destruct(Byte*);
extern void test();

#endif