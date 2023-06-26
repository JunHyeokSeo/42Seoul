/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveTest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:53:53 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/23 14:04:06 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

	if (dst == NULL && src == NULL)
		return (NULL);
	local_dst = (char *)dst;
	while (n--)
	{
		ft_memset(local_dst++, *(char *)src++, 1);
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	// 임의의 데이터 생성
	char data1[] = "abcdefghijklmnopqrstuvwxyz";
	int length1 = sizeof(data1) / sizeof(char);
	char data2[] = "abcdefghijklmnopqrstuvwxyz";
	int length2 = sizeof(data2) / sizeof(char);

	// 데이터 이동 전 출력
	printf("Before memmove: ");
	//for (int i = 0; i < length1; i++)
	//{
	//	printf("%c ", data1[i]);
	//}
	printf("%s", data1);
	printf("\n");
	printf("Before memmove: ");
	//for (int i = 0; i < length2; i++)
	//{
	//	printf("%c ", data2[i]);
	//}
	printf("%s", data2);
	printf("\n");

	// memmove 함수 사용하여 데이터 이동
	memmove(data1 + 3, data1, 3 * sizeof(int));
	ft_memmove(data2 + 3, data2, 3 * sizeof(int));

	// 데이터 이동 후 출력
	printf("After memmove: ");
	//for (int i = 0; i < length1; i++)
	//{
	//	printf("%c ", data1[i]);
	//}
	printf("%s", data1);
	printf("\n");
	printf("After memmove: ");
	//for (int i = 0; i < length2; i++)
	//{
	//	printf("%c ", data2[i]);
	//}
	printf("%s", data2);
	printf("\n");
	return 0;
}
