/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:57:10 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/27 16:54:12 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	cal_size(int dec)
{
	size_t	count;

	count = 0;
	if (dec <= 0)
		count++;
	while (dec)
	{
		dec /= 10;
		count++;
	}
	return (count);
}

char	*input_char(char *str, int dec)
{
	if (dec < 0)
	{
		*str++ = '-';
		dec *= -1;
	}
	if (dec >= 10)
		str = input_char(str, dec / 10);
	*str = (dec % 10) + '0';
	return (++str);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)ft_calloc(cal_size(n) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	input_char(str, n);
	return (str);
}
