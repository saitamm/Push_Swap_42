/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cas_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:13:13 by sait-amm          #+#    #+#             */
/*   Updated: 2024/03/24 15:48:58 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_Node **s, char *str)
{
	t_Node	*d;
	t_Node	*tmp;
	int		l;

	d = *s;
	tmp = d->next;
	l = d->data;
	d->data = tmp->data;
	tmp->data = l;
	if (str)
		ft_putstr_fd(str, 1);
}

int	ft_position_max(t_Node *s)
{
	t_Node	*top;
	int		pos;
	int		max;
	int		l;

	max = s->data;
	top = s;
	pos = 0;
	l = 0;
	while (top)
	{
		if (top->data > max)
		{
			max = top->data;
			pos = l;
		}
		top = top->next;
		l++;
	}
	return (pos);
}

void	ft_sort_3(t_Node **s)
{
	int	l;

	l = ft_position_max(*s);
	if (is_sorted_stack(*s))
		return ;
	else if (l == 0)
	{
		rotate(s, "ra");
		if (!is_sorted_stack(*s))
			swap_stack(s, "sa");
	}
	else if (l == 1)
	{
		rotate_reverce(s, "rra");
		if (!is_sorted_stack(*s))
			swap_stack(s, "sa");
	}
	else
		swap_stack(s, "sa");
}
