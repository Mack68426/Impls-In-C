#ifndef TYPES_H
#define TYPES_H
#include <stddef.h>
#include <stdlib.h>


typedef enum _DataType DataType; 
typedef enum _Boolean boolean;

enum _DataType
{   
    Null = -1,
    Undefined = 0,
    Char,
    Short,
    Long,
    Int,
    Float,
    Double,
    LongDouble
};

enum _Boolean {false, true};


#endif // !TYPES_H