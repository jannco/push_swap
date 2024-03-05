/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:57:52 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/23 20:12:57 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp;
	long	headvalue;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		headvalue = tmp->value;
		while (tmp->next)
		{
			tmp->value = tmp->next->value;
			tmp = tmp->next;
		}
		tmp->value = headvalue;
	}
}

void	ft_ra(t_stack **a)
{
	ft_rotate(a);
	ft_miniprintf("ra\n");
}

void	ft_rb(t_stack **b)
{
	ft_rotate(b);
	ft_miniprintf("rb\n");
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_miniprintf("rr\n");
}
