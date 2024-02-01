/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_miniprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:38:31 by yadereve          #+#    #+#             */
/*   Updated: 2024/02/01 08:48:32 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_miniformat(va_list *ap, const char *str, int i)
{
	if (str[i] == 's')
		ft_putstr(va_arg(*ap, char *));
}

void	ft_miniprintf(const char *str, ...)
{
	int		i;
	va_list	ap;

	if (!str)
		return ;
	va_start (ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_miniformat(&ap, str, i);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
}
