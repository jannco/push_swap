/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:18:18 by yadereve          #+#    #+#             */
/*   Updated: 2024/02/01 18:30:10 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2 && !av[1][0])
	{
		ft_miniprintf("Error\n");
		return (1);
	}
	create_stack(&a, ac, av);
	if (!sorted(a))
	{
		if (size_stack(&a) == 2)
			ft_sa(&a);
		else if (size_stack(&a) == 3)
			mini_sort(&a);
		else
			perform_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
