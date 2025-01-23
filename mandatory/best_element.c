/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:05:48 by sait-amm          #+#    #+#             */
/*   Updated: 2024/03/24 15:48:41 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	max_absolute(int a, int b)
{
	if (abs(a) > abs(b))
		return (abs(a));
	return (abs(b));
}

void	nb_mv(t_Node **b)
{
	t_Node	*tmp;

	tmp = *b;
	while (tmp)
	{
		if ((tmp->move_a >= 0 && tmp->move_b >= 0) || (tmp->move_a <= 0
				&& tmp->move_b <= 0))
			tmp->nb_mv = max_absolute(tmp->move_a, tmp->move_b);
		else
			tmp->nb_mv = abs(tmp->move_a) + abs(tmp->move_b);
		tmp = tmp->next;
	}
}

int	*best_elem(t_Node *b, t_Node *a)
{
	t_Node	*tmp;
	int		m;
	int		*best_move;

	tmp = b;
	cost_node(&b, a);
	m = tmp->nb_mv;
	best_move = (int *)malloc(sizeof(int) * 2);
	if (!best_move)
		return (NULL);
	best_move[0] = tmp->move_a;
	best_move[1] = tmp->move_b;
	while (tmp)
	{
		if (tmp->nb_mv < m)
		{
			m = tmp->nb_mv;
			best_move[0] = tmp->move_a;
			best_move[1] = tmp->move_b;
		}
		tmp = tmp->next;
	}
	return (best_move);
}
