/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:11:31 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/30 15:16:24 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*local_s;

	if (n == 0)
		return (NULL);
	local_s = (unsigned char *)s;
	while (n--)
	{
		if (*local_s == (unsigned char)c)
			return (local_s);
		local_s++;
	}
	if (c == '\0' && *local_s == '\0')
		return (local_s);
	return (NULL);
}
