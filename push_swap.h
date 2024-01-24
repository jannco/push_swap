/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:18:06 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/24 19:14:33 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_stack
{
	long int		value;
	int				position;
	int				cost;
	struct s_stack	*besti;
	struct s_stack	*next;
}	t_stack;

typedef struct s_values
{
	long int	smalest_pos;
	long int	smalest_pos_besti;
}	t_values;

void	create_stack(t_stack **a, int ac, char **av);
void	free_stack(t_stack **a);
void	*ft_calloc(size_t n, size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_miniformat(va_list *ap, const char *str, int i);
void	ft_putstr(char *str);
void	ft_miniprintf(const char *str, ...);
void	mini_sort(t_stack **a);
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
void	ft_swap(t_stack **a);
void	ft_rotate(t_stack **a);
void	ft_r_rotate(t_stack **a);
void	ft_push(t_stack **a, t_stack **b);
long	ft_strtolong(char **str, int *err);
int		ft_strcmp(char *s1, char *s2);
void	ft_exit(t_stack **a);
void	checkers(t_stack **a);
long	size_stack(t_stack **a);
bool	sorted(t_stack *a);
void	perform_sort(t_stack **a, t_stack **b);
int		find_median(t_stack **a);
void	get_besti(t_stack **a, t_stack **b, int small_high);
void	position(t_stack **a, t_stack **b);
void	set_pos(t_stack **stak);
int		get_small(t_stack **a, t_stack **b);
void	set_small_besti(t_stack **a, t_stack **b);
long	lookforsmalest(t_stack **a);
int		calculate_cost(t_stack **a, int pos);
void	move_better(t_stack **a, t_stack **b);
void	organize_b(t_stack **b, long i);
void	organize_a(t_stack **a, long i);
void	rotate_until_is_last(t_stack **a);
int		find_pos(int last, t_stack **a);
int		find_last(t_stack **a);

#endif
