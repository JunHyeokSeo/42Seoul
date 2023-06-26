#include <stdio.h>
#include <string.h>

#define BUF_SIZE 20

int main(void)
{
	char src[BUF_SIZE] = "hello, world!";
	char *dst = NULL;

	// len이 src의 길이보다 긴 경우
	size_t len = BUF_SIZE;
	memmove(dst, src, len);
	printf("src: %s\n", src);
	printf("dst: %s\n", dst);

	// len이 dst의 길이보다 긴 경우
	memset(dst, 0, BUF_SIZE);
	len = BUF_SIZE;
	memmove(dst, src, len);
	printf("src: %s\n", src);
	printf("dst: %s\n", dst);

	return 0;
}
