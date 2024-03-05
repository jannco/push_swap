/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:07:32 by yadereve          #+#    #+#             */
/*   Updated: 2024/03/05 17:20:06 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute_moves(char *instruct, t_stack **a, t_stack **b)
{
	if (ft_strcmp("ra\n", instruct) == 0)
		ft_rotate(a);
	else if (ft_strcmp("rb\n", instruct) == 0)
		ft_rotate(b);
	else if (ft_strcmp("sa\n", instruct) == 0)
		ft_swap(a);
	else if (ft_strcmp("sb\n", instruct) == 0)
		ft_swap(b);
	else if (ft_strcmp("pa\n", instruct) == 0)
		ft_push(b, a);
	else if (ft_strcmp("pb\n", instruct) == 0)
		ft_push(a, b);
	else if (ft_strcmp("rra\n", instruct) == 0)
		ft_r_rotate(a);
	else if (ft_strcmp("rrb\n", instruct) == 0)
		ft_r_rotate(b);
	else
		ft_exit(a);
}

void	check_moves(t_stack **a, t_stack **b)
{
	char	*instruct;
	int		fd;

	fd = 0;
	instruct = get_next_line(fd);
	while (instruct != NULL)
	{
		execute_moves(instruct, a, b);
		free(instruct);
		instruct = get_next_line(fd);
	}
	free(instruct);
	if (sorted(*a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
