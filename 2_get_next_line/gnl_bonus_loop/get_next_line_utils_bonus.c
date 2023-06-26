/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:10:56 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/26 16:50:01 by junhseo          ###   ########.fr       */
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
