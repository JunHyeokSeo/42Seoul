#include<string.h>
#include<stdio.h>

int main()
{
	char *dst = "123456789123456789";
	char *src = "junhseo";
	int dstsize = 10;
	printf("%lu\n", strlcat(dst, src, dstsize));
}