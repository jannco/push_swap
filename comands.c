/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:23:56 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/19 10:54:11 by yadereve         ###   ########.fr       */
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
