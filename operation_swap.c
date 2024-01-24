/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:52:23 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/23 20:12:28 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	long int	tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->value;
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = tmp;
	}
}

void	ft_sa(t_stack **a)
{
	ft_swap(a);
	ft_miniprintf("sa\n");
}

void	ft_sb(t_stack **b)
{
	ft_swap(b);
	ft_miniprintf("sb\n");
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_miniprintf("ss\n");
}
