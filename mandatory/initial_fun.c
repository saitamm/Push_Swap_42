/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:58:40 by sait-amm          #+#    #+#             */
/*   Updated: 2024/03/28 15:10:07 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initial_pos(t_Node **b)
{
	t_Node	*temp;
	int		i;

	i = 0;
	temp = *b;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

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
	int	*l;

	l = (int *)malloc(n * sizeof(int));
	if (!l)
		return ;
	lis->n = ft_size_stack(a);
	lis->str = ft_to_array(a, n);
	lis->max_length = length(lis->str, n, l);
	lis->res = longestincreasingsub(lis->str, n);
	ft_sort_array(lis->str, n);
	free(l);
}
