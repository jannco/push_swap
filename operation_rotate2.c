/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:57:52 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/23 20:13:17 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_r_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	tmp2 = *stack;
	if (*stack && (*stack)->next)
	{
		while (tmp2->next)
			tmp2 = tmp2->next;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp2->next = *stack;
		*stack = tmp2;
		tmp->next = NULL;
	}
}

void	ft_rra(t_stack **a)
{
	ft_r_rotate(a);
	ft_miniprintf("rra\n");
}

void	ft_rrb(t_stack **b)
{
	ft_r_rotate(b);
	ft_miniprintf("rrb\n");
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_r_rotate(a);
	ft_r_rotate(b);
	ft_miniprintf("rrr\n");
}
