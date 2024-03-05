/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:48:43 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/23 20:13:33 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **stack, t_stack **stack2)
{
	t_stack	*tmp;

	if (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->next = *stack2;
		*stack2 = *stack;
		*stack = tmp;
	}
}

void	ft_pa(t_stack **a, t_stack **b)
{
	ft_push(b, a);
	ft_miniprintf("pa\n");
}

void	ft_pb(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	ft_miniprintf("pb\n");
}
