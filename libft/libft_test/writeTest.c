#include<unistd.h>

int main ()
{
	int a;

	a = 97;
	write(1, &a, 4);
}