/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:01:31 by sait-amm          #+#    #+#             */
/*   Updated: 2024/04/03 20:36:38 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initial_lis(int **lis, int **lis_index, int n)
{
	int	*l1;
	int	*l2;
	int	i;

	l1 = *lis;
	l2 = *lis_index;
	i = 0;
	while (i < n)
	{
		l1[i] = 1;
		l2[i] = -1;
		i++;
	}
}

void	initial_array(t_Node *a, int n, t_array *lis)
{
	lis->n = ft_size_stack(a);
	lis->str = ft_to_array(a, n);
	lis->max_length = length(lis->str, n, lis);
	lis->res = LongestincreasingSub(lis->str, n);
	ft_sort_array(lis->str, n);
}
