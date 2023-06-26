#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("ls -al");
    write(1, "hello ", 6);
    printf("world");
}