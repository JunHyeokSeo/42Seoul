#include<stdio.h>
#include<string.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;
	int result;

	i = 0;
	result = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		result = s1[i] - s2[i];
		if (result != 0)
			return (result);
		i++;
	}
	return (0);
}

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	return (ft_strncmp((char *)s1, (char *)s2, n));
}

int main()
{
	char a[50] = "42seoul junhseo";
	char b[50] = "42seoul honyi";
	
	int result;
	result = memcmp((void *)a, (void *)b, 0);
	printf("%d\n", result);
	result = ft_memcmp((void *)a, (void *)b, 0);
	printf("%d\n", result);
}