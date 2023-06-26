/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:59:11 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/24 21:37:03 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *src)
{
	int		src_len;
	char	*new;

	src_len = ft_strlen(src) + 1;
	new = (char *)malloc(src_len);
	if (new == NULL)
		return (NULL);
	return ((char *)ft_memcpy(new, src, src_len));
}
