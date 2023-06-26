/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:46:10 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/12 13:27:51 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		lst;
	int			count;
	const char	*type;

	type = "cspdiuxX%";
	va_start(lst, str);
	count = 0;
	while (*str)
	{
		if (*str == '%' && ft_strchr(type, *(++str)))
			print_lst(*str, &lst, &count);
		else
			put_chr(*str, &count);
		str++;
		if (count == -1)
			return (-1);
	}
	va_end(lst);
	return (count);
}
