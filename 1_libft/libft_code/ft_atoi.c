/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:23:46 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/30 15:20:40 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	sum;

	sign = 1;
	sum = 0;
	while ((9 <= *str && 13 >= *str) || 32 == *str)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && '9' >= *str)
	{
		if (((sum * 10) + (*str - '0')) < sum)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		sum = (sum * 10) + (*str - '0');
		str++;
	}
	return (sum * sign);
}
