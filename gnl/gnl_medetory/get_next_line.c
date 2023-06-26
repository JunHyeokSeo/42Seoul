/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:13:05 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/16 21:31:29 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buff;
	int			index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!create_buff(fd, &save))
		return (NULL);
	index = 0;
	while (*(save + index) != '\n' && *(save + index) != '\0')
		index++;
	if (*(save + index) == '\n')
		return (get_string_before_newline(++index, &save));
	buff = NULL;
	if (!create_buff(fd, &buff))
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	return (update_buffers(fd, &save, &buff, index));
}
