/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:10:56 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/26 17:49:02 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_buff(int fd, char **buff)
{
	int	rv;

	if (*buff)
		return (*buff);
	*buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!*buff)
	{
		*buff = NULL;
		return (NULL);
	}
	rv = read(fd, *buff, BUFFER_SIZE);
	if (rv < 0)
	{
		free(*buff);
		*buff = NULL;
		return (NULL);
	}
	else if (rv == 0)
		**buff = '\0';
	else
		*(*buff + rv) = '\0';
	return (*buff);
}

char	*ft_strjoin(char *s1, char *s2, size_t total_len)
{
	char	*str;
	char	*new;

	str = s1;
	while (*str++)
		total_len++;
	str = s2;
	while (*str++)
		total_len++;
	new = (char *)malloc(total_len + 1);
	if (!new)
	{
		new = (char *)malloc(1);
		if (!new)
			return (NULL);
		*new = '\0';
		return (new);
	}
	str = new;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (new);
}

char	*get_string_before_newline(int index, char **save)
{
	char	*new;
	char	*tmp;
	int		input_index;

	new = (char *)malloc(index + 1);
	if (!new)
	{
		free(*save);
		*save = NULL;
		new = (char *)malloc(1);
		*new = '\0';
		return (new);
	}
	*(new + index) = '\0';
	input_index = -1;
	while (++input_index < index)
		*(new + input_index) = *(*save + input_index);
	tmp = ft_strjoin("", (*save + index), 0);
	free(*save);
	*save = tmp;
	return (new);
}

char	*get_last_line(int index, char **save)
{
	char	*new;
	int		input_index;

	new = (char *)malloc(index + 1);
	if (!new)
	{
		free(new);
		free(*save);
		*save = NULL;
		return (NULL);
	}
	*(new + index) = '\0';
	input_index = -1;
	while (++input_index < index)
		*(new + input_index) = *(*save + input_index);
	free(*save);
	*save = NULL;
	return (new);
}

char	*update_buffers(int fd, char **save, char **buff, int index)
{
	char	*result;

	result = NULL;
	while (1)
	{
		*buff = NULL;
		if (!create_buff(fd, buff))
		{
			free(*save);
			*save = NULL;
			return (NULL);
		}
		if (**buff == '\0')
		{
			free(*buff);
			if (**save != '\0')
				result = get_last_line(index, save);
			free(*save);
			*save = NULL;
			return (result);
		}
		result = find_next_line(save, buff, &index);
		if (result)
			return (result);
	}
}
