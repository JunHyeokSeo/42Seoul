/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:37:44 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/12 11:07:40 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_x(unsigned long long n, int *count, char *base)
{
	char	tmp;

	if (n >= 16)
		put_x(n / 16, count, base);
	if (*count == -1)
		return ;
	tmp = base[n % 16];
	error_check(write(1, &tmp, 1), count);
}
