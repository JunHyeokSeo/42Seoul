/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:13:05 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/26 16:51:56 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_head	*create_head(int fd, t_head **head)
{
	if (*head)
		return (*head);
	*head = (t_head *)malloc(sizeof(t_head));
	if (!*head)
		return (NULL);
	(*head)->first_node = create_node(fd);
	if (!(*head)->first_node)
	{
		free(*head);
		*head = NULL;
		return (NULL);
	}
	return (*head);
}

t_list	*create_node(int fd)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->buff = read_file(fd);
	if (!new_node->buff)
	{
		free(new_node);
		return (NULL);
	}
	new_node->fd = fd;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

char	*get_string(int index, char *buff)
{
	char	*new;
	int		input_index;

	new = (char *)malloc(index + 1);
	if (!new)
	{
		new = (char *)malloc(1);
		if (!new)
			return (NULL);
		*new = '\0';
		return (new);
	}
	*(new + index) = '\0';
	input_index = -1;
	while (++input_index < index)
		*(new + input_index) = *(buff + input_index);
	return (new);
}

char	*update_buffers(int fd, int index, t_head **head, t_list **node)
{
	char	*result;
	char	*buff;

	result = NULL;
	while (1)
	{
		buff = read_file(fd);
		if (!buff)
		{
			delete_node(fd, head);
			return (NULL);
		}
		if (*buff == '\0')
		{
			free(buff);
			if (*((*node)->buff + (*node)->index) != '\0')
				result = get_string(index, ((*node)->buff + (*node)->index));
			delete_node(fd, head);
			return (result);
		}
		result = find_next_line(node, &buff, &index);
		if (result)
			return (result);
	}
}

char	*get_next_line(int fd)
{
	static t_head	*head = {NULL};
	char			*result;
	t_list			*node;
	int				index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!create_head(fd, &head))
		return (NULL);
	node = find_node(fd, &head);
	if (!node)
		return (NULL);
	index = 0;
	while (*(node->buff + node->index + index) != '\n' \
			&& *(node->buff + node->index + index) != '\0')
		index++;
	if (*(node->buff + node->index + index) == '\n')
	{
		result = get_string(++index, (node->buff + node->index));
		node->index += index;
		return (result);
	}
	return (update_buffers(fd, index, &head, &node));
}
