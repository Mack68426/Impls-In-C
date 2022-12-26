#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


union 
{
    unsigned char _data;

    struct _bField
    {
        unsigned b0:1;
        unsigned b1:1;
        unsigned b2:1;
        unsigned b3:1;
        unsigned b4:1;
        unsigned b5:1;
        unsigned b6:1;
        unsigned b7:1;
    } __bit_field__;
} bf;

struct _Bit 
{
    unsigned (*get)(struct _bField);
    unsigned (*LSHIFT)(struct _bField, unsigned);
    unsigned (*RSHIFT)(struct _bField, unsigned);
    unsigned (*AND)(struct _bField, struct _bField);
    unsigned (*OR)(struct _bField, struct _bField);
    unsigned (*NOT)(struct _bField, struct _bField);
    unsigned (*XOR)(struct _bField, struct _bField);
} ;


int main()
{
    bf._data = 10;

    printf("b0:\t%d\n",bf.__bit_field__.b0);
    printf("b1:\t%d\n",bf.__bit_field__.b1);
    printf("b2:\t%d\n",bf.__bit_field__.b2);
    printf("b3:\t%d\n",bf.__bit_field__.b3);
    printf("b4:\t%d\n",bf.__bit_field__.b4);
    printf("b5:\t%d\n",bf.__bit_field__.b5);
    printf("b6:\t%d\n",bf.__bit_field__.b6);
    printf("b7:\t%d\n",bf.__bit_field__.b7);


    printf("_data:\t%d\n",bf._data);
    printf("\n");
    
    return 0;
}