/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:57:31 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/12 13:46:39 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted(t_stack *a)
{
	if (a)
	{
		while ((a)->next)
		{
			if (a->value > a->next->value)
				return (false);
			a = a->next;
		}
		return (true);
	}
	return (true);
}
