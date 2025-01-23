/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:52:00 by sait-amm          #+#    #+#             */
/*   Updated: 2024/04/03 21:18:21 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static int	ft_whitespace(char c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

long	ft_atoi(const char *c, int *nb, int flag)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_whitespace(c[i]) == 1)
		i++;
	if (c[i] == '+' || c[i] == '-')
	{
		if (c[i] == '-')
			sign = (-1) * sign;
		i++;
	}
	while (c[i] >= '0' && c[i] <= '9')
	{
		flag = 0;
		result = result * 10 + c[i++] - '0';
		if (sign * result > INT_MAX || sign * result < INT_MIN)
			return (0);
	}
	return (*nb = result * sign, !flag);
}
