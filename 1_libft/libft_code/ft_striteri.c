/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:18:49 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/27 15:34:12 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	index;
	size_t	s_len;

	index = 0;
	s_len = ft_strlen(s);
	while (index < s_len)
	{
		f(index, (s + index));
		index++;
	}
}
