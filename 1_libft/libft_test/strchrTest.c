#include<string.h>
#include<stdio.h>

char *ft_strchr(const char *s, int c)
{
	char *local_s;

	local_s = (char *)s;
	while (*local_s)
	{
		if (*local_s == c)
			return (local_s);
		else
			local_s++;
	}
	if (c == '\0')
		return (local_s);
	return (0);
}

int main()
{
	char a[50] = "42seoul junhseo";
	char *b;
	b = ft_strchr(a, 50);
	printf("%s\n", b);
	b = strchr(a, 50);
	printf("%s\n", b);
}