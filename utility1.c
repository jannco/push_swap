/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:10:51 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/11 10:07:31 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pos(t_stack **stak)
{
	t_stack	*tmp;

	tmp = *stak;
	while (tmp)
	{
		tmp->position = 0;
		tmp = tmp->next;
	}
}

void	position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		i;
	int		j;

	tmp_a = *a;
	tmp_b = *b;
	tmp_b->besti = NULL;
	i = 0;
	j = 0;
	set_pos(a);
	set_pos(b);
	while (tmp_a)
	{
		tmp_a->position = i;
		i++;
		tmp_a = tmp_a->next;
	}
	while (tmp_b)
	{
		tmp_b->position = j;
		j++;
		tmp_b = tmp_b->next;
	}
}

void	get_besti(t_stack **a, t_stack **b, int small_high)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	position(a, b);
	while (tmp_b)
	{
		tmp_a = *a;
		small_high = get_small(&tmp_a, &tmp_b);
		while (tmp_a)
		{
			if (tmp_a->value > tmp_b->value && tmp_a->value == small_high)
			{
				tmp_b->besti = tmp_a;
				break;
			}
			tmp_a = tmp_a->next;
		}
		if (tmp_b->besti == NULL)
			set_small_besti(a, &tmp_b);
		tmp_b->cost = calculate_cost(b, tmp_b->position);
		tmp_b->besti->cost = calculate_cost(a, tmp_b->besti->position);
		tmp_b = tmp_b->next;
	}
}
