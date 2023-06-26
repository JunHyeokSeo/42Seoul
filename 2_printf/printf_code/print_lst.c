/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:24:11 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/12 13:33:49 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_lst(const char type, va_list *lst, int *count)
{
	if (type == 'c')
		put_chr(va_arg(*lst, int), count);
	else if (type == 's')
		put_str(va_arg(*lst, char *), count);
	else if (type == 'p')
		put_mem(va_arg(*lst, void *), count);
	else if (type == 'd' || type == 'i')
		put_nbr(va_arg(*lst, int), count);
	else if (type == 'u')
		put_nbr(va_arg(*lst, unsigned int), count);
	else if (type == 'x')
		put_x(va_arg(*lst, unsigned int), count, "0123456789abcdef");
	else if (type == 'X')
		put_x(va_arg(*lst, unsigned int), count, "0123456789ABCDEF");
	else if (type == '%')
		put_per(count);
}
