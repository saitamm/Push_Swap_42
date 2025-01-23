/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:55:56 by sait-amm          #+#    #+#             */
/*   Updated: 2024/03/24 15:53:23 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Node	*ft_add_beg(t_Node **head, int c)
{
	t_Node	*s;

	s = (t_Node *)malloc(sizeof(t_Node));
	if (!s)
		return (NULL);
	s->data = c;
	s->next = NULL;
	s->next = *head;
	*head = s;
	return (*head);
}

int	ft_size_stack(t_Node *s)
{
	int	k;

	k = 0;
	while (s)
	{
		k++;
		s = s->next;
	}
	return (k);
}

int	is_sorted_stack(t_Node *a)
{
	t_Node	*tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	max_stack(t_Node *a)
{
	int		max;
	t_Node	*tmp;

	max = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

int	min_stack(t_Node *a)
{
	int		min;
	t_Node	*tmp;

	tmp = a;
	min = INT_MAX;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}
