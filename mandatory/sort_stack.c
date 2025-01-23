/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:20:40 by sait-amm          #+#    #+#             */
/*   Updated: 2025/01/23 09:14:37 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_a(t_Node **a, t_Node **b)
{
	ft_to_b_empty(b, a);
	if (min_pos_stack(*a) < ft_size_stack(*a) / 2)
	{
		while (is_sorted_stack(*a) != 1)
			rotate(a, "ra");
	}
	else
	{
		while (is_sorted_stack(*a) != 1)
			rotate_reverce(a, "rra");
	}
}

void	ft_to_b_empty(t_Node **b, t_Node **a)
{
	int		*min_move;

	while (ft_stack_empty(*b) != 0)
	{
		cost_node(b, *a);
		min_move = best_elem(*b, *a);
		ft_push_to_a(a, b, min_move);
		free(min_move);
	}
}

int	ft_stack_empty(t_Node *b)
{
	if (b == NULL)
		return (0);
	return (1);
}

int	min_pos_stack(t_Node *a)
{
	int		m;
	t_Node	*tmp;
	int		min_pos;

	tmp = a;
	m = min_stack(a);
	initial_pos(&a);
	min_pos = 0;
	while (tmp)
	{
		if (tmp->data == m)
			min_pos = tmp->pos;
		tmp = tmp->next;
	}
	return (min_pos);
}

void	sort_inf_5(t_Node **a, t_Node **b, int n)
{
	if (n == 2)
	{
		if (is_sorted_stack(*a) == 0)
			swap_stack(a, "sa");
	}
	else if (n == 3)
		ft_sort_3(a);
	else if (n == 4 || n == 5)
	{
		push(a, b, "pb");
		push(a, b, "pb");
		ft_sort_3(a);
		ft_sort_a(a, b);
	}
	else
		return ;
}
