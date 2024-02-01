/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:18:28 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/31 20:59:07 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_str_to_long(char **str, int *err)
{
	long	i;
	long	n;
	int		f;

	i = 0;
	n = 0;
	f = 1;
	while (str[0][i] == 32 || (str[0][i] >= 9 && str[0][i] <= 13))
		i++;
	f = (str[0][i] != '-') - (str[0][i] == '-');
	i += (str[0][i] == '+' || str[0][i] == '-');
	if (!str[0][i])
		*err = 1;
	while (str[0][i] >= '0' && str[0][i] <= '9')
	{
		n = n * 10 + (str[0][i] - '0');
		if ((n * f) > INT_MAX || (n * f) < INT_MIN)
			*err = 1;
		i++;
	}
	str[0] += i;
	return (n * f);
}
