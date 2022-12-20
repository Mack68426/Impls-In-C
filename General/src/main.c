#include <stdio.h>
#include <stdlib.h>

#include "basis.h"
#include "object.h"
#include "general.h"


int main(int argc, char const *argv[])
{
    General* i = new(General, 10);
    General* f = new(General, 0.1F);
    General* str = new(General, "10");
    
    printf("%d\n", i);
    printf("%.2f\n", f);
    printf("%s\n", str);

    delete(General,i);
    delete(General,f);
    delete(General,str);

    return 0;
}