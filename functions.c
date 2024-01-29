/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:18:43 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/29 18:39:46 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted(t_stack *a)
{
	if (a)
	{
		while ((a)->next)
		{
			if (a->value > a->next->value)
				return (false);
			a = a->next;
		}
		return (true);
	}
	return (true);
}

long	size_stack(t_stack **a)
{
	long	i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	if (*a)
	{
		while (tmp)
		{
			tmp = tmp->next;
			i++;
		}
		return (i);
	}
	return (0);
}

void	create_stack(t_stack **a, int ac, char **av)
{
	t_stack	*node;
	t_stack	*end;
	int		i;
	int		err;

	err = 0;
	i = 1;
	while (i < ac)
	{
		node = ft_calloc(sizeof(t_stack), 1);
		node->value = ft_str_to_long(&av[i], &err);
		if (*a == NULL)
			*a = node;
		else
			end->next = node;
		if (err || !(*av[i] == 32 || *av[i] == '\0'
				|| (*av[i] >= 0 && *av[i] <= 13)))
			ft_exit(a);
		i += (*av[i] == '\0');
		end = node;
	}
	checkers(a);
}
