/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:57:52 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/05 18:22:34 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
