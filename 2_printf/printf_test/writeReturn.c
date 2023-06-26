#include <unistd.h>
#include <stdio.h>
int main ()
{
	int a = write(1, "adf", 123221312);
	printf("\n");
	printf("%d\n", a);
}