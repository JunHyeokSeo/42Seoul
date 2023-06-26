#include"libft.h"
#include<stdio.h>

int ft_atoi(const char *str)
{
	long sum;

	sum = 0;
	while ('0' <= *str && '9' >= *str)
	{
		printf("%lu\n", (unsigned long)((sum * 10) + (*str - '0')));
		if ((unsigned long)(sum * 10) + (*str - '0') > LONG_MAX)
		{
			printf("fail\n");
			return (0);
		}
		sum = (sum * 10) + (*str - '0');
		str++;
	}
	return (sum);
}

int main()
{
	ft_atoi("9223372036854775808");
}