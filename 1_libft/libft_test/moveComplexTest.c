#include <stdio.h>
#include <string.h>
#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr = (unsigned char *)b;

	while (len--)
	{
		*ptr++ = c;
	}
	return b;
}

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	char *local_dst;

	local_dst = (char *)dst;
	while (n--)
	{
		// memset, char로 형변환하여 1byte씩 내용복사.
		ft_memset(local_dst++, *(char *)src++, 1);
	}
	return (dst);
}

void *ft_memmove(void *dst, const void *src, size_t len)
{
		char *local_dst;

		// char pointer for casting.
		local_dst = (char *)dst;

		// need tmp for save src.
		char tmp[len];
		int index = 0;
		ft_memcpy(tmp, src, len);
		while (index < len)
		{
			ft_memset(local_dst++, tmp[index], 1);
			index++;
		}
		return (dst);
}

int main()
{
	char str[] = "memmove can be very useful......";
	ft_memmove(str + 20, str + 15, 11);
	printf("Result: %s\n", str);
	return 0;
}