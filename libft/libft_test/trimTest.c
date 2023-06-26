#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void *ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr = (unsigned char *)b;
	// 해당 방식은 동적할당된 포인터 또는 배열을 인자로 받아야함
	while (len--)
	{
		*ptr++ = c;
	}
	return (b);
}

char *ft_strchr(const char *s, int c)
{
	char *local_s;

	local_s = (char *)s;
	while (*local_s)
	{
		if (*local_s == c)
			return (local_s);
		local_s++;
	}
	if (c == '\0')
		return (local_s);
	return (NULL);
}

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

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	char *local_dst;

	// edit (need understand)
	if (dst == NULL && src == NULL)
		return (NULL);

	local_dst = (char *)dst;
	while (n--)
	{
		ft_memset(local_dst++, *(char *)src++, 1);
	}
	return (dst);
}

static size_t my_trim(char const *s1, char const *set, size_t index)
{
	int triger;

	if (index == 0)
		triger = 0;
	else
		triger = 1;
	while (ft_strchr(set, *(s1 + index)))
	{
		if (triger == 0)
			index++;
		else
			index--;
	}
	return (index);
}

char *ft_strtrim(char const *s1, char const *set)
{
	size_t len;
	size_t start;
	size_t end;
	size_t len_of_new;
	char *new;

	len = ft_strlen((char *)s1);
	start = my_trim(s1, set, 0);
	end = my_trim(s1, set, len);

	len_of_new = (end - start) + 1;
	new = (char *)malloc(len_of_new + 1);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, (s1 + start), len_of_new);
	*(new + len_of_new) = '\0';
	return (new);
}

int main()
{
	char str1[] = "  Hello, World! \n\t ";
	char str2[] = "abcdeeefffggghijk";
	char str3[] = "This is a sentence.";
	char str4[] = "000example000";
	char *trimmed_str;
	char *set = " e.0";

	// Test Case 1: Remove all whitespaces
	trimmed_str = ft_strtrim(str1, set);
	printf("Test Case 1:\n");
	printf("Before: '%s'\n", str1);
	printf("After: '%s'\n", trimmed_str);
	free(trimmed_str);

	// Test Case 2: Remove all 'e' characters
	trimmed_str = ft_strtrim(str2, set);
	printf("Test Case 2:\n");
	printf("Before: '%s'\n", str2);
	printf("After: '%s'\n", trimmed_str);
	free(trimmed_str);

	// Test Case 3: Remove all '.' characters
	trimmed_str = ft_strtrim(str3, set);
	printf("Test Case 3:\n");
	printf("Before: '%s'\n", str3);
	printf("After: '%s'\n", trimmed_str);
	free(trimmed_str);

	// Test Case 4: Remove all '0' characters
	trimmed_str = ft_strtrim(str4, set);
	printf("Test Case 4:\n");
	printf("Before: '%s'\n", str4);
	printf("After: '%s'\n", trimmed_str);
	free(trimmed_str);

	return 0;
}