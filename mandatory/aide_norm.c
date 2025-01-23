/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aide_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:22:28 by sait-amm          #+#    #+#             */
/*   Updated: 2024/03/31 23:54:11 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fun_norm2(int *n, int m, t_Node *a)
{
	t_Node	*top1;

	top1 = a;
	if (*n == ft_size_stack(a) || (*n == ft_size_stack(a) && m == INT_MAX))
	{
		top1 = a;
		m = min_stack(a);
		while (top1)
		{
			if (top1->data == m)
				*n = top1->pos;
			top1 = top1->next;
		}
	}
}

void	fun_norm(int *lis, int *a, int *b, int i)
{
	if (lis[i] > *a)
	{
		*a = lis[i];
		*b = i;
	}
}

void	norm_error(t_Node **a, char **str)
{
	free_list(a);
	free_split(str, len_str(str));
	write(2, "Error\n", 6);
	exit(1);
}
