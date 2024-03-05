/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:46:44 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/12 21:28:15 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort(t_stack **a)
{
	t_stack	*tmp;

	tmp = (*a)->next;
	if ((*a)->value < tmp ->value && tmp -> value > tmp->next->value
		&& (*a)->value < tmp->next->value)
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if ((*a)->value < tmp->value && tmp->value > tmp->next->value
		&& (*a)->value > tmp->next->value)
		ft_rra(a);
	else if ((*a)->value > tmp->value && tmp->value > tmp->next->value
		&& (*a)->value > tmp->next->value)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if ((*a)->value > tmp->value && tmp->value < tmp->next->value
		&& (*a)->value > tmp->next->value)
		ft_ra(a);
	else if ((*a)->value > tmp->value && tmp->value < tmp->next->value
		&& (*a)->value < tmp->next->value)
		ft_sa(a);
}
