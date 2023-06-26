/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:54:26 by junhseo           #+#    #+#             */
/*   Updated: 2023/04/12 11:24:58 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	put_chr(char c, int *count);
void	put_str(char *s, int *count);
void	put_nbr(long n, int *count);
int		ft_printf(const char *str, ...);
void	put_x(unsigned long long n, int *count, char *base);
void	put_per(int *count);
void	put_mem(void *ptr, int *count);
void	print_lst(const char type_spec, va_list *lst, int *count);
void	error_check(int check, int *count);

#endif