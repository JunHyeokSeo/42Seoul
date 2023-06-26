/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:13:05 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/26 16:30:42 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		return (NULL);
	str = new;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (new);
}

char	*read_file(int fd)
{
	char	*new;
	int		rv;

	new = (char *)malloc(BUFFER_SIZE + 1);
	if (!new)
		return (NULL);
	rv = read(fd, new, BUFFER_SIZE);
	if (rv < 0)
	{
		free(new);
		return (NULL);
	}
	else if (rv == 0)
		*new = '\0';
	else
		*(new + rv) = '\0';
	return (new);
}

t_list	*find_node(int fd, t_head **head)
{
	t_list	*list;
	t_list	*tail;
	t_list	*new;

	list = (*head)->first_node;
	while (list)
	{
		if (list->fd == fd)
			return (list);
		tail = list;
		list = list->next;
	}
	new = create_node(fd);
	if (!new)
		return (NULL);
	tail->next = new;
	return (new);
}


void	delete_node(int fd, t_head **head)
{
	t_list	*tmp;
	t_list	*del_node;

	if ((*head)->first_node->fd == fd)
	{
		tmp = (*head)->first_node;
		(*head)->first_node = tmp->next;
		free(tmp->buff);
		free(tmp);
	}
	else
	{
		tmp = (*head)->first_node;
		while (tmp->next && tmp->next->fd != fd)
			tmp = tmp->next;
		del_node = tmp->next;
		tmp->next = del_node->next;
		free(del_node->buff);
		free(del_node);
	}
	if (!(*head)->first_node)
	{
		free(*head);
		*head = NULL;
	}
}

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

char	*find_next_line(t_list **node, char **buff, int *index)
{
	char	*result;
	char	*tmp;

	tmp = ft_strjoin(((*node)->buff + (*node)->index), *buff, 0);
	free((*node)->buff);
	free(*buff);
	(*node)->buff = tmp;
	(*node)->index = 0;
	*index = 0;
	while (*((*node)->buff + *index) != '\n' \
			&& *((*node)->buff + *index) != '\0')
		(*index)++;
	if (*((*node)->buff + *index) == '\n')
	{
		result = get_string(++(*index), ((*node)->buff));
		(*node)->index += *index;
		return (result);
	}
	return (NULL);
}

char	*update_buffers(int fd, int index, t_head **head, t_list **node)
{
	char	*result;
	char	*buff;

	while (1)
	{
		result = NULL;
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

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *path = "exam.txt";
	int fd = open(path, O_RDWR);
	char *result;

	result = get_next_line(fd);
	printf("%s", result);
	free(result);
	result = get_next_line(fd);
	printf("%s", result);
	free(result);
	close(fd);
}