/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 10:19:33 by sait-amm          #+#    #+#             */
/*   Updated: 2024/04/03 01:33:25 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search(int *array, int a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (array[i] == a)
			return (1);
		i++;
	}
	return (0);
}

int	max(int *lis, int n)
{
	int	m;
	int	i;

	m = lis[0];
	i = 1;
	while (i < n)
	{
		if (lis[i] > m)
			m = lis[i];
		i++;
	}
	return (m);
}

int	length(int *array, int n, int *l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
		l[i++] = 1;
	i = 1;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (array[i] > array[j] && l[i] < l[j] + 1)
				l[i] = l[j] + 1;
			j++;
		}
		i++;
	}
	return (max(l, n));
}

int	comp_stack(t_Node *a, int data_cmp)
{
	t_Node	*temp;

	temp = a;
	while (temp)
	{
		if (data_cmp < temp->data)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	ft_push_to_b(t_Node **a, t_Node **b, t_array *l)
{
	int	size_stack;

	size_stack = ft_size_stack(*a);
	while (size_stack > l->max_length)
	{
		if (search(l->res, (*a)->data, l->max_length) == 0)
		{
			push(a, b, "pb");
			size_stack--;
		}
		else
		{
			rotate(a, "ra");
		}
	}
}
