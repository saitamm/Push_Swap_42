/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:04:25 by sait-amm          #+#    #+#             */
/*   Updated: 2024/03/31 23:45:00 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	target_a(t_Node *a, int k)
{
	t_Node	*top1;
	int		m;
	int		n;

	initial_pos(&a);
	top1 = a;
	m = INT_MAX;
	n = ft_size_stack(a);
	while (top1)
	{
		if (top1->data > k && top1->data <= m)
		{
			m = top1->data;
			n = top1->pos;
		}
		top1 = top1->next;
	}
	fun_norm2(&n, m, a);
	return (n);
}

void	count_move_b(t_Node **b)
{
	t_Node	*tmp;
	int		mid_b;

	initial_pos(b);
	mid_b = ft_size_stack(*b) / 2;
	tmp = *b;
	while (tmp)
	{
		if (tmp->pos < mid_b)
			tmp->move_b = tmp->pos;
		else
			tmp->move_b = -(ft_size_stack(*b) - tmp->pos);
		tmp = tmp->next;
	}
}

void	count_move_a(t_Node *a, t_Node **b)
{
	t_Node	*tmp;
	int		m;
	int		mid_a;

	tmp = *b;
	mid_a = ft_size_stack(a) / 2;
	while (tmp)
	{
		m = target_a(a, tmp->data);
		if (m < mid_a)
			tmp->move_a = m;
		else
		{
			tmp->move_a = -(ft_size_stack(a) - m);
		}
		tmp = tmp->next;
	}
}

void	num_move(t_Node *a, t_Node **b)
{
	count_move_a(a, b);
	count_move_b(b);
}

void	cost_node(t_Node **b, t_Node *a)
{
	initial_pos(b);
	num_move(a, b);
	nb_mv(b);
}
