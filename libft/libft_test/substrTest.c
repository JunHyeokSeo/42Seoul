#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t ft_strlen(char *s)
{
	size_t count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

void *ft_memset(void *b, int c, size_t len)
{
	char *ptr;

	ptr = (char *)b;
	while (len--)
		*ptr++ = c;
	return (b);
}

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	char *local_dst;
	char *local_src;

	if (dst != src)
	{
		local_dst = (char *)dst;
		local_src = (char *)src;
		while (n--)
			ft_memset(local_dst++, *(local_src++), 1);
	}
	return (dst);
}

char *ft_strdup(const char *src)
{
	int src_len;
	char *new;

	if (src == NULL)
		return (NULL);
	src_len = ft_strlen((char *)src) + 1;
	new = (char *)malloc(src_len);
	if (new == NULL)
		return (NULL);
	return ((char *)ft_memcpy(new, src, src_len));
}

// ft_substr 함수 정의 (여기서는 작성하지 않음)
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *new;
	size_t str_len;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen((char *)s);
	if (str_len <= start || len == 0)
		return (ft_strdup(""));
	if (str_len - start < len)
		return (ft_strdup(s + start));
	new = (char *)malloc(len);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s + start, len);
	return (new);
}

int main()
{
	char str[] = "Hello, world!";
	unsigned int start;
	size_t len;

	// 시작 위치와 길이를 사용자로부터 입력받음
	printf("Enter start: ");
	scanf("%u", &start);
	printf("Enter length: ");
	scanf("%zu", &len);

	// ft_substr 함수를 호출하여 부분 문자열 추출
	char *ft_sub = ft_substr(str, start, len);

	// substr 함수를 호출하여 부분 문자열 추출
	char sub[len + 1];
	strncpy(sub, str + start, len);
	sub[len] = '\0';

	// 추출된 부분 문자열 출력
	printf("ft_substr: %s\n", ft_sub);
	printf("substr: %s\n", sub);

	// ft_substr 함수와 substr 함수가 동일한 결과를 반환하는지 비교
	if (strcmp(ft_sub, sub) == 0)
	{
		printf("ft_substr and substr return the same substring.\n");
	}
	else
	{
		printf("ft_substr and substr return different substrings.\n");
	}

	// ft_substr 함수에서 할당한 메모리 해제
	free(ft_sub);

	return 0;
}