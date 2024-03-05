/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:42:46 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/24 19:38:51 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(t_stack **a)
{
	int				median;
	int				i;
	long long int	sum;
	t_stack			*tmp;

	i = 0;
	sum = 0;
	tmp = *a;
	while (tmp)
	{
		sum += tmp->value;
		tmp = tmp->next;
		i++;
	}
	median = sum / i;
	return (median);
}

void	perform_sort(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		median;
	int		small_high;

	tmp = *a;
	median = find_median(a);
	small_high = 0;
	while (size_stack(a) > 3)
	{
		if (tmp->value < median)
			ft_pb(a, b);
		else
			ft_ra(a);
		tmp = *a;
		median = find_median(a);
	}
	mini_sort(a);
	while (size_stack(b) > 0)
	{
		get_besti(a, b, small_high);
		move_better(a, b);
	}
	rotate_until_is_last(a);
}
