/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:18:43 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/16 17:20:11 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stack **a, int ac, char **av)
{
	t_stack	*node;
	t_stack	*end;
	int		i;
	int		err;

	err = 0;
	i = 1;
	while (i < ac)
	{
		node = ft_calloc(sizeof(t_stack), 1);
		if (!node)
			exit(EXIT_FAILURE);
		node->value = ft_strtolong(&av[i], &err);
		if (*a == NULL)
			*a = node;
		else
			end->next = node;
		if (err || !(*av[i] == 32 || *av[i] == '\0'
				|| (*av[i] >= 0 && *av[i] <= 13)))
			ft_exit(a);
		i += (*av[i] == '\0');
		end = node;
	}
	checkers(a);
}
