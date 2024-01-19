/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:48:43 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/19 11:01:27 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
