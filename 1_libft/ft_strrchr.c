/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:54:11 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/27 15:32:53 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*local_s;

	local_s = NULL;
	while (*s)
	{
		if (*s == (char)c)
			local_s = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (local_s);
}
