/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:05:37 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/24 20:51:59 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*new;

	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)ft_calloc(total_len, sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_strlcat(new, s1, total_len);
	ft_strlcat(new, s2, total_len);
	return (new);
}
