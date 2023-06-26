/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:01:58 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/30 09:45:09 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_word_num(char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str != c && *(str + 1) == c)
			count++;
		else if (*str != c && *(str + 1) == '\0')
			count++;
		str++;
	}
	return (count);
}

size_t	get_word_len(char *str, char c)
{
	size_t	len;

	len = 0;
	while (*str != c && *str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}

char	*copy_string(char *str, size_t word_len)
{
	char	*new;

	new = (char *)ft_calloc(word_len + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, str, word_len);
	return (new);
}

void	allocation_failure(char **split)
{
	size_t	index;

	index = 0;
	while (split[index])
		free(split[index++]);
	free(split);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	char	**split;

	if (s == NULL)
		return (NULL);
	split = (char **)ft_calloc(get_word_num((char *)s, c) + 1, sizeof(char *));
	if (split == NULL)
		return (NULL);
	index = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		split[index] = copy_string((char *)s, get_word_len((char *)s, c));
		if (split[index] == NULL)
		{
			allocation_failure(split);
			return (NULL);
		}
		s += get_word_len((char *)s, c);
		index++;
	}
	return (split);
}
