/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:08:29 by sait-amm          #+#    #+#             */
/*   Updated: 2024/04/03 00:19:26 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_Node **a, t_Node **b, char *str)
{
	t_Node	*s;

	if (!(*a) || !a)
		return ;
	if (ft_size_stack(*a) == 0)
		return ;
	s = *a;
	*a = (*a)->next;
	s->next = *b;
	*b = s;
	if (str)
		ft_putstr_fd(str, 1);
}

void	swap_stack(t_Node **s, char *str)
{
	t_Node	*d;
	t_Node	*tmp;
	int		l;

	d = *s;
	if (ft_size_stack(d) < 2)
		return ;
	tmp = d->next;
	l = d->data;
	d->data = tmp->data;
	tmp->data = l;
	if (str)
		ft_putstr_fd(str, 1);
}

void	rotate_reverce(t_Node **s, char *str)
{
	t_Node	*d;
	t_Node	*p;

	d = *s;
	p = NULL;
	if (!(*s) || ft_size_stack(*s) < 2)
		return ;
	while (d->next)
	{
		p = d;
		d = d->next;
	}
	p->next = NULL;
	d->next = *s;
	*s = d;
	if (str)
		ft_putstr_fd(str, 1);
}

void	rotate(t_Node **s, char *str)
{
	t_Node	*p;
	t_Node	*temp;

	if (!(*s) || !s)
		return ;
	p = *s;
	if (ft_size_stack(p) < 2)
		return ;
	*s = (*s)->next;
	temp = *s;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = p;
	temp->next->next = NULL;
	if (str)
		ft_putstr_fd(str, 1);
}

void	rrr(t_Node **a, t_Node **b, char *str)
{
	rotate_reverce(a, NULL);
	rotate_reverce(b, NULL);
	if (str)
		ft_putstr_fd(str, 1);
}
