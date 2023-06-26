#include<stdio.h>
#include<string.h>
#include"libft.h"

size_t ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;
	int result;
	unsigned char *str1;
	unsigned char *str2;

	i = 0;
	result = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] || str2[i]) && i < n)
	{
		result = str1[i] - str2[i];
		if (result != 0)
			return (result);
		i++;
	}
	return (0);
}

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t needle_len = ft_strlen((char *)needle);

	if (needle_len == 0)
		return (char *)haystack;

	//str1에서의 탐색 범위 len을 활용
	//str1의 탐색 시작 범위에서 needle_len을 더한 것이 탐색 범위 바깥이라면 탐색하지 않고 NULL 반환.
	while (*haystack && len >= needle_len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return (char *)haystack;
		haystack++;
		len--;
	}
	return NULL;
}

int main()
{
	//len의 정확한 활용 범위에 대해 조사할것
	//함수 전반적인 이해가 필요해보임
	char a[50] = "42seoul jund";
	char b[50] = "seoul jund";
	printf("%s\n", strnstr(a, b, 10));
	printf("%s\n", ft_strnstr(a, b, 10));
}