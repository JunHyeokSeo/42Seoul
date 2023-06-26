/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoiTest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhseo <junhseo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:15:39 by junhseo           #+#    #+#             */
/*   Updated: 2023/03/30 11:48:22 by junhseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include"libft.h"

int ft_atoi(const char *str);

////아래 함수는 원함수와 동일한 결과를 내도록 수정한 코드.
////해당 함수를 paco 돌려보고 이상 없으면 사용할 것.
//int ft_atoi(const char *str)
//{
//	long long sign;
//	long long sum;

//	sign = 1;
//	sum = 0;
//	while ((9 <= *str && 13 >= *str) || 32 == *str)
//		str++;
//	if (*str == '+' || *str == '-')
//	{
//		if (*str == '-')
//			sign *= -1;
//		str++;
//	}
//	while ('0' <= *str && '9' >= *str)
//	{
//		if ((sum * sign) < 0 && sign * ((sum * 10) + (*str - '0')) >= 0)
//			return (0);
//		if ((sum * sign) > 0 && sign * ((sum * 10) + (*str - '0')) <= 0)
//			return (-1);
//		sum = (sum * 10) + (*str - '0');
//		str++;
//	}
//	return (sum * sign);
//}
int ft_atoi(const char *str)
{
	int sign;
	long sum;

	sign = 1;
	sum = 0;
	while ((9 <= *str && 13 >= *str) || 32 == *str)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && '9' >= *str)
	{
		if (((sum * 10) + (*str - '0')) < sum)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		sum = (sum * 10) + (*str - '0');
		str++;
	}
	return (sum * sign);
}

int main()
{
	const char *test_strings[] = {"9223372036854775807", "-9999999999999999999999", "-1234ra", "  1234", "1234  ", "   +1234  ", "  -1234 ", "  12.34", "abc123", "  +abc123", "  -abc123"};
	// int expected_results[] = {1234, 0, -1234, 1234, 1234, 1234, -1234, 12, 0, 0, 0};
	int num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

	for (int i = 0; i < num_tests; i++)
	{
		const char *test_str = test_strings[i];
		int expected_result = atoi(test_str);
		int actual_result = ft_atoi(test_str);

		if (actual_result == expected_result)
		{
			printf("PASS: '%s' -> %d\n", test_str, actual_result);
		}
		else
		{
			printf("FAIL: '%s' -> expected %d but got %d\n", test_str, expected_result, actual_result);
		}
	}

	return 0;
}