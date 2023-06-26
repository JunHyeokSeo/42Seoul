
#include<stdio.h>
#include<string.h>

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
	unsigned char *ptr;

	ptr = (unsigned char *)b;
	while (len--)
	{
		*ptr++ = c;
	}
	return (b);
}

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	char *local_dst;

	if (dst != src)
	{
		local_dst = (char *)dst;
		while (n--)
		{
			ft_memset(local_dst++, *(char *)src++, 1);
		}
	}
	return (dst);
}

void *ft_memmove(void *dst, const void *src, size_t len)
{
	char *local_src;

	local_src = (char *)src;
	if (dst > src)
	{
		while (len)
		{
			ft_memset(dst + len - 1, *(local_src + len - 1), 1);
			len--;
		}
	}
	else if (dst < src)
		ft_memcpy(dst, src, len);
	return (dst);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t src_len;

	src_len = ft_strlen((char *)src);
	if (dstsize <= 0)
		return (src_len);
	ft_memmove(dst, src, dstsize - 1);
	if (dstsize < src_len)
		dst[dstsize] = '\0';
	else
		dst[src_len] = '\0';
	return (src_len);
}

int main()
{
	char dest[100];
	char src[40] = "This is a test string";
	size_t size = sizeof(dest);

	// Test case 1: source string fits into destination buffer
	printf("Test case 1\n");
	strlcpy(dest, src, size);
	printf("dest: %s\n", dest);
	printf("src: %s\n", src);

	// Test case 2: source string does not fit into destination buffer
	printf("Test case 2\n");
	strlcpy(dest, src, 5);
	printf("dest: %s\n", dest);
	printf("src: %s\n", src);

	// Test case 3: source string is empty
	printf("Test case 3\n");
	strlcpy(dest, "", size);
	printf("dest: %s\n", dest);

	// Test case 4: destination buffer is empty
	printf("Test case 4\n");
	strlcpy("", src, size);
	printf("dest: %s\n", dest);
	printf("src: %s\n", src);

	return 0;
}
