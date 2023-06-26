#include <stdio.h>
#include <string.h>

int main()
{
	char *src = NULL;
	char *dest = "junhseo";
	size_t len = 1;

	printf("%s\n", (char *)memcpy(dest, src, len));

	return 0;
}
