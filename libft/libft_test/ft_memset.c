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
