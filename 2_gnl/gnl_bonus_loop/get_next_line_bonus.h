/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:10:01 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/26 17:52:35 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_linked_list
{
	char					*buff;
	int						fd;
	int						index;
	struct s_linked_list	*next;
}	t_list;

typedef struct s_head_of_list
{
	t_list	*first_node;
}	t_head;

t_head	*create_head(int fd, t_head **head);
t_list	*find_node(int fd, t_head **head);
t_list	*create_node(int fd);
char	*find_next_line(t_list **node, char **buff, int *index);
char	*get_string(int index, char *buff);
char	*ft_strjoin(char *s1, char *s2, size_t total_len);
char	*read_file(int fd);
char	*get_next_line(int fd);
char	*update_buffers(int fd, int index, t_head **head, t_list **node);
void	delete_node(int fd, t_head **head);

#endif