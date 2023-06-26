#include<stdio.h>
#include<ctype.h>

int ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int main()
{
	printf("%c\n", toupper('a'));
	printf("%c\n", toupper('A'));
	printf("%c\n", toupper('4'));
	printf("%c\n", toupper(' '));
	// printf("%c\n", toupper('\0'));
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", ft_toupper('A'));
	printf("%c\n", ft_toupper('4'));
	printf("%c\n", ft_toupper(' '));
	// printf("%c\n", ft_toupper('\0'));
}