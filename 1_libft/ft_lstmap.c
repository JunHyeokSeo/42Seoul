/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:35:40 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/29 11:56:42 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp_node;
	void	*tmp_content;

	if (lst == NULL || f == NULL || del == NULL)
		return (lst);
	head = NULL;
	while (lst)
	{
		tmp_content = f(lst->content);
		tmp_node = ft_lstnew(tmp_content);
		if (tmp_node == NULL)
		{
			ft_lstclear(&head, del);
			del(tmp_content);
			return (NULL);
		}
		ft_lstadd_back(&head, tmp_node);
		lst = lst->next;
	}
	return (head);
}
