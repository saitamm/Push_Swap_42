/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:17:31 by sait-amm          #+#    #+#             */
/*   Updated: 2024/03/24 15:49:39 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_positive(t_Node **a, t_Node **b, int *move)
{
	int	cost_a;
	int	cost_b;

	cost_a = move[0];
	cost_b = move[1];
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b, "rr");
		cost_a--;
		cost_b--;
	}
	if (cost_a != 0)
	{
		while (cost_a-- > 0)
			rotate(a, "ra");
	}
	if (cost_b != 0)
	{
		while (cost_b-- > 0)
			rotate(b, "rb");
	}
}

void	cost_negative(t_Node **a, t_Node **b, int *move)
{
	int	cost_a;
	int	cost_b;

	cost_a = move[0];
	cost_b = move[1];
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b, "rrr");
		cost_a++;
		cost_b++;
	}
	if (cost_a != 0)
	{
		while (cost_a++ < 0)
			rotate_reverce(a, "rra");
	}
	if (cost_b != 0)
	{
		while (cost_b++ < 0)
			rotate_reverce(b, "rrb");
	}
}

void	ft_sign_1(t_Node **a, t_Node **b, int *move)
{
	while (move[0])
	{
		rotate(a, "ra");
		move[0]--;
	}
	while (move[1])
	{
		rotate_reverce(b, "rrb");
		move[1]++;
	}
}

void	ft_sign_2(t_Node **a, t_Node **b, int *move)
{
	while (move[0])
	{
		rotate_reverce(a, "rra");
		move[0]++;
	}
	while (move[1])
	{
		rotate(b, "rb");
		move[1]--;
	}
}

void	ft_push_to_a(t_Node **a, t_Node **b, int *move)
{
	if ((move[0] >= 0 && move[1] >= 0))
		cost_positive(a, b, move);
	else if (move[0] <= 0 && move[1] <= 0)
		cost_negative(a, b, move);
	else if (move[0] >= 0 && move[1] <= 0)
		ft_sign_1(a, b, move);
	else if (move[0] <= 0 && move[1] >= 0)
		ft_sign_2(a, b, move);
	push(b, a, "pa");
}
