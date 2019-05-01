#include <stdio.h>

extern void sayHello1();
extern void sayHello2();

int
main()
{
    printf("Hello, world!\n");
    sayHello1();
    sayHello2();
    return 0;
}

