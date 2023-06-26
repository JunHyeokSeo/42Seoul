/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:05:40 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/24 21:36:37 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	str_len;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (str_len <= start || len == 0)
		return (ft_strdup(""));
	if (str_len - start < len)
		return (ft_strdup(s + start));
	new = (char *)ft_calloc(len + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s + start, len);
	return (new);
}
