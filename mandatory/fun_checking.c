/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:54:06 by sait-amm          #+#    #+#             */
/*   Updated: 2024/03/25 02:00:18 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\f' || c == '\n'
		|| c == '\v')
		return (1);
	else
		return (0);
}

int	ft_checkdigit(char *str)
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

int	ft_checkrepeat(t_Node **s, int k)
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
