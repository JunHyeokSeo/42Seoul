#include <stdarg.h>
#include <stdio.h>

void prt(char *s, ...)
{
	va_list lst;
	va_start(lst, s);
	unsigned int a = va_arg(lst, unsigned int);
	printf("a: %u\n", a);
	va_end(lst);
}

int main ()
{
	int b = -1;
	prt("ad", b);
	return 0;
}