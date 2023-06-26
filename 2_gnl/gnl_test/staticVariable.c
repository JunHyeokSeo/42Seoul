/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staticVariable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:49:32 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/14 11:52:45 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	func(void)
{
	static int	ptr = 0;

	ptr++;
	return (ptr);
}

int	main(void)
{
	printf("%d\n", func());
	return (0);
}
