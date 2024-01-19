/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:57:52 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/05 18:22:19 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
