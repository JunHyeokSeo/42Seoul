/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:38:37 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/27 17:17:01 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long num;
	char tmp;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	if (num >= 10)
		ft_putnbr_fd((int)num / 10, fd);
	tmp = (num % 10) + '0';
	write(fd, &tmp, 1);
}

//unsigned int -> int -> long long
int main()
{
	ft_putnbr_fd(4294967295, 1);
}