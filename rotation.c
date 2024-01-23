/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:06:09 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/23 08:18:21 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_last(t_stack **a)
{
	int		last;
	t_stack	*tmp;

	tmp = *a;
	last = tmp->value;
	while (tmp)
	{
		if (tmp->value > last)
			last = tmp->value;
		tmp = tmp->next;
	}
	return (last);
}

int	find_pos(int last, t_stack **a)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->value == last)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}

void	rotate_until_is_last(t_stack **a)
{
	int	pos;
	int	size;
	int	last;

	last = find_last(a);
	pos = find_pos(last, a) + 1;
	size = size_stack(a) - pos;
	if (pos < size)
	{
		while (pos--)
			ft_ra(a);
	}
	else
	{
		while (size--)
		{
			ft_rra(a);
		}
	}
}
