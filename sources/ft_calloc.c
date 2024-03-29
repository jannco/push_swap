/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:17:17 by yadereve          #+#    #+#             */
/*   Updated: 2024/01/29 15:02:26 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*a;

	a = (void *) malloc(n * size);
	if (!a)
		exit (EXIT_FAILURE);
	ft_bzero(a, (n * size));
	return (a);
}
/*
int	main(void)
{
	int	i, n;
	int	*a;

	printf("Number of elements to be entered:");
	n = 3;
	printf("%d\n", n);

	a = (int*)ft_calloc(n, sizeof(int));
	printf("Enter %d numbers:\n",n);
	for ( i=0 ; i < n ; i++ )
	{
		a[i] = n * i;
		printf("%d\n", a[i]);
	}
	printf("The numbers entered are: ");
	for (i = 0; i < n; i++)
	{
		printf("%d, ",a[i]);
	}
	free (a);
	return (0);
} */
