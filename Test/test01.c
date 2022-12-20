#include <stdio.h>
#include <stdlib.h>


void outer()
{
    auto void inner();

    void inner()
    {
        printf("I'm nested!\n");
    }

    inner();
}

int main()
{
    outer();
} 
