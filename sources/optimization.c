/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:20:52 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/10 19:57:23 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	organize_a(t_stack **a, long i)
{
	if ((size_stack(a) / 2) >= i)
	{
		while (i > 0)
		{
			ft_ra(a);
			i--;
		}
	}
	else
	{
		while (i < size_stack(a))
		{
			ft_rra(a);
			i++;
		}
	}
}

void	organize_b(t_stack **b, long i)
{
	if ((size_stack(b) / 2) >= i)
	{
		while (i > 0)
		{
			ft_rb(b);
			i--;
		}
	}
	else
	{
		while (i < size_stack(b))
		{
			ft_rrb(b);
			i++;
		}
	}
}

void	move_better(t_stack **a, t_stack **b)
{
	t_values	smalest;
	int			i;
	t_stack		*tmp;

	tmp = *b;
	i = INT_MAX;
	smalest.smalest_pos = 0;
	smalest.smalest_pos_besti = 0;
	while (tmp)
	{
		if ((tmp->cost + tmp->besti->cost) < i)
		{
			smalest.smalest_pos = tmp->position;
			smalest.smalest_pos_besti = tmp->besti->position;
			i = tmp->cost + tmp->besti->cost;
		}
		tmp = tmp->next;
	}
	organize_a(a, smalest.smalest_pos_besti);
	organize_b(b, smalest.smalest_pos);
	ft_pa(a, b);
}
