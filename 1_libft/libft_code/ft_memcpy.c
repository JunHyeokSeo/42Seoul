/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:53:49 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/30 13:19:55 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*local_dst;
	unsigned char	*local_src;

	if (dst != src)
	{
		local_dst = (unsigned char *)dst;
		local_src = (unsigned char *)src;
		while (n--)
			*local_dst++ = *local_src++;
	}
	return (dst);
}
