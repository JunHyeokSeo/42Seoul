/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:54:16 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/27 15:23:14 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	size_t	s_len;
	char	*str;

	index = 0;
	s_len = ft_strlen(s);
	str = (char *)ft_calloc(s_len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (index < s_len)
	{
		*(str + index) = f(index, *(s + index));
		index++;
	}
	return (str);
}
