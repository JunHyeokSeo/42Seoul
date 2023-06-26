#include <stdarg.h>
#include <unistd.h>
#include <string.h>

void vag(char *str, ...)
{
    va_list lst;
    char tmp;
    int len = strlen(str);
    va_start(lst, str);
    write(1, str, len);
    write(1, "\n", 1);
    for (size_t i = 0; i < 4; i++)
    {
        tmp = va_arg(lst, int);
        write(1, &tmp, 1);
        write(1, "\n", 1);
    }
    va_end(lst);
}

#include <stdio.h>

int main()
{
    vag("junhseo", 'a', 'b', 'c', 'd');
    return 0;
}
