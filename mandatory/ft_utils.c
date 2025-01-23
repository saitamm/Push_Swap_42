/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:16:38 by sait-amm          #+#    #+#             */
/*   Updated: 2024/03/24 15:51:02 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_Node **a, t_Node **b, char *str)
{
	t_Node	*s;

	if (*a == NULL)
		return ;
	s = *a;
	*a = (*a)->next;
	s->next = *b;
	*b = s;
	if (str)
		ft_putstr_fd(str, 1);
}

void	rotate_reverce(t_Node **s, char *str)
{
	t_Node	*d;
	t_Node	*p;

	d = *s;
	p = NULL;
	if (!(*s) || ft_size_stack(*s) == 1)
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

	p = *s;
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

void	rr(t_Node **a, t_Node **b, char *str)
{
	rotate(a, NULL);
	rotate(b, NULL);
	if (str)
		ft_putstr_fd(str, 1);
}
