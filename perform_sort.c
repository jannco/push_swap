/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:42:46 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/23 20:05:39 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(t_stack **a)
{
	int				*values;
	int				median;
	int				i;
	long long int	sum;
	t_stack			*tmp;

	i = -1;
	sum = 0;
	values = (int *)malloc(size_stack(a) * sizeof(int));
	if (!values)
		exit(EXIT_FAILURE);
	tmp = *a;
	while (tmp)
	{
		values[++i] = tmp->value;
		tmp = tmp->next;
	}
	i = -1;
	while (++i < size_stack(a))
		sum += values[i];
	median = sum / i;
	free(values);
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
		{
			ft_pb(a, b);
		}
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
