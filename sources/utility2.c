/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiliti2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:38:11 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/23 08:13:22 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_small(t_stack **a, t_stack **b)
{
	int		small;
	t_stack	*tmp;

	tmp = *a;
	small = INT_MAX;
	while (tmp)
	{
		if (tmp->value < small && tmp->value > (*b)->value)
			small = tmp->value;
		tmp = tmp->next;
	}
	return (small);
}

long	lookforsmalest(t_stack **a)
{
	t_stack		*tmp;
	long int	smalest;

	smalest = INT_MAX;
	if (*a)
	{
		tmp = *a;
		while (tmp->next)
		{
			if (tmp->value < smalest)
				smalest = tmp->value;
			tmp = tmp->next;
		}
		return (smalest);
	}
	return (0);
}

void	set_small_besti(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	long	smalest;

	smalest = lookforsmalest(a);
	tmp = *b;
	while (tmp)
	{
		if (tmp->value == smalest)
		{
			(*b)->besti = tmp;
			break ;
		}
		tmp = tmp->next;
	}
}

int	calculate_cost(t_stack **a, int pos)
{
	int	cost;

	if (size_stack(a) / 2 > pos)
		cost = pos;
	else
		cost = size_stack(a) - pos;
	return (cost);
}
