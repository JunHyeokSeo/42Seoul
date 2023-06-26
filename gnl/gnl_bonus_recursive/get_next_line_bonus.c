/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:13:05 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/26 13:11:47 by junhseo          ###   ########.fr       */
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

char	*update_buffers(int fd, int index, t_head **head, char *tmp)
{
	t_list	*node;
	char	*buff;

	node = find_node(fd, head);
	buff = read_file(fd);
	if (!buff)
	{
		delete_node(fd, head);
		return (NULL);
	}
	if (*buff == '\0')
	{
		free(buff);
		if (*(node->buff + node->index) != '\0')
			tmp = get_string(index, (node->buff + node->index));
		delete_node(fd, head);
		return (tmp);
	}
	tmp = ft_strjoin((node->buff + node->index), buff, 0);
	free(node->buff);
	free(buff);
	node->buff = tmp;
	node->index = 0;
	return (get_next_line(fd));
}

char	*get_next_line(int fd)
{
	static t_head	*head = {NULL};
	char			*result;
	t_list			*tmp;
	int				index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!create_head(fd, &head))
		return (NULL);
	tmp = find_node(fd, &head);
	if (!tmp)
		return (NULL);
	index = 0;
	while (*(tmp->buff + tmp->index + index) != '\n'\
			&& *(tmp->buff + tmp->index + index) != '\0')
		index++;
	if (*(tmp->buff + tmp->index + index) == '\n')
	{
		result = get_string(++index, (tmp->buff + tmp->index));
		tmp->index += index;
		return (result);
	}
	return (update_buffers(fd, index, &head, NULL));
}
