/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:53:53 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/30 13:19:20 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*local_dst;
	unsigned char	*local_src;

	local_dst = (unsigned char *)dst;
	local_src = (unsigned char *)src;
	if (dst > src)
	{
		while (len)
		{
			*(local_dst + len - 1) = *(local_src + len - 1);
			len--;
		}
	}
	else if (dst < src)
		ft_memcpy(dst, src, len);
	return (dst);
}
