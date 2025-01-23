/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:13:09 by sait-amm          #+#    #+#             */
/*   Updated: 2024/04/03 21:16:26 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_whitespace(char c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

int	ft_checkdigit_bonus(char *str)
{
	int	i;

	i = 0;
	while (ft_whitespace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkrepeat_bonus(t_Node **s, int k)
{
	t_Node	*d;

	d = *s;
	while (d != NULL)
	{
		if (d->data == k)
			return (1);
		d = d->next;
	}
	return (0);
}

t_Node	*ft_add_beg_bonus(t_Node **head, int c)
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
