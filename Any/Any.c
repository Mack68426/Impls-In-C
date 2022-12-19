/* not done yet */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Any.h"

#define __allocate(ptr, size) { if( !( (ptr) = (typeof(ptr))malloc(size)) ) {  perror("Allocation Failed\n"); exit(0);} return ptr;}
#define __release(ptr) { free(ptr) }
#define __new(name, var) { (typeof(name) *) p = __allocate(name, sizeof(name)); ; return (p = var);}

// typedef void * (Any);

typedef Generic Any;




int main(int argc, char const *argv[])
{
    Any *i = (int *)10;
    Any *f = _new(f, 4.32F); 
    Any *str = "F";
    
    printf("%d\n", i);
    printf("%.2f\n", f);
    printf("%s\n", str);

    return 0;
}

