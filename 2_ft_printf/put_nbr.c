/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:38:37 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/12 10:52:35 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_nbr(long n, int *count)
{
	char	tmp;

	if (n < 0)
	{
		error_check(write(1, "-", 1), count);
		if (*count == -1)
			return ;
		n *= -1;
	}
	if (n >= 10)
		put_nbr(n / 10, count);
	if (*count == -1)
		return ;
	tmp = (n % 10) + '0';
	error_check(write(1, &tmp, 1), count);
}
