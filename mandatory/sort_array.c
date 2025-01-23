/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:04:54 by sait-amm          #+#    #+#             */
/*   Updated: 2024/03/24 15:57:40 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_array(int *str, int n)
{
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		j = i;
		while (j > 0 && str[j - 1] > str[j])
		{
			ft_swap(&str[j], &str[j - 1]);
			j--;
		}
		i++;
	}
}

int	*ft_to_array(t_Node *s, int l)
{
	int		*str;
	int		i;
	t_Node	*a;

	i = 0;
	a = s;
	str = (int *)malloc(l * sizeof(int));
	if (!str)
		return (NULL);
	while (i < l)
	{
		str[i] = a->data;
		a = a->next;
		i++;
	}
	return (str);
}
