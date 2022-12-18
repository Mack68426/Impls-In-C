#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int b = 1;

    typeof(a) c = 10;

    printf("%d", c);

    return 0;
}