#include <stdio.h>

int print(int a, int b, int c)
{
	printf("a = %d, b = %o, c = %x\n", a, b, c);
	return 0;
}

int main()
{
	print(12, 012, 0x12);
	return 0;
}