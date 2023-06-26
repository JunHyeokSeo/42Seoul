#include<string.h>
#include<stdio.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	char *local_s;
	size_t index;

	local_s = (char *)s;
	index = 0;
	// 종료조건
	// 1. 문자열에서 문자를 찾음(EOF or not EOF)
	// 2. 문자를 찾지 못함(EOF라 무조건적으로 존재하지만, n에 걸려서 탐색을 못한 경우 포함)
	while (local_s[index] && index < n)
	{
		if (local_s[index] == c)
			return ((local_s + index));
		index++;
	}
	if (c == '\0' && local_s[index] == '\0')
		return ((local_s + index));
	return (0);
}

int main()
{
	char a[50] = "42seoul junhseo";
	void *b;
	b = ft_memchr(a, '\0', 30);
	printf("%s\n", (char *)b);
	b = memchr(a, '\0', 30);
	printf("%s\n", (char *)b);
}