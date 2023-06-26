#include<string.h>
#include<stdio.h>

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

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t len_src;
	size_t loop;
	//배열 대신 포인터를 사용하여 문자열을 접근하기 위해 포인터 사용.
	char *local_src;

	loop = 1;
	local_src = (char *)src;
	while (*local_src || loop < dstsize)
	{
		*dst++ = *local_src++;
		loop++;
	}
	*dst = '\0';
	len_src = ft_strlen(src);
	return (len_src);
}

int main()
{
	char a[50] = "junhseo";
	char b[50] = "42seoul";

	char c[50] = "junhseo";
	char d[50] = "42seoul";
	printf("%s : %lu\n", a, ft_strlcpy(a, b, -1));
	// printf("%s : %lu\n", a, strlcpy(c, d, -1));
}