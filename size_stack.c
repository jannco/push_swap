/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:06:15 by yadereve          #+#    #+#             */
/*   Updated: 2023/12/20 12:08:49 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	size_stack(t_stack **a)
{
	long	i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	if (*a)
	{
		while (tmp)
		{
			tmp = tmp->next;
			i++;
		}
		return (i);
	}
	return (0);
}
