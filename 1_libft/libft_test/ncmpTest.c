/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncmpTest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:54:08 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/24 12:39:06 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t 			i;
	int				result;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	result = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] || str2[i]) && i < n)
	{
		result = str1[i] - str2[i];
		if (result != 0)
			return (result);
		i++;
	}
	return (0);
}

int main()
{
	printf("%d\n", ft_strncmp("t\200", "t\0", 2));
}