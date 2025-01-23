/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LongestincreasingSub.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:21:58 by sait-amm          #+#    #+#             */
/*   Updated: 2024/04/03 01:35:15 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_l(int a, int b)
{
	int	*lis;

	lis = malloc(2 * sizeof(int));
	if (!lis)
		return (NULL);
	lis[0] = a;
	lis[1] = b;
	return (lis);
}

int	*max_len(int *arr, int n, int **lis, int **lis_index)
{
	int	i;
	int	j;
	int	max_length;
	int	max_index;

	i = 1;
	max_length = 1;
	max_index = 0;
	initial_lis(lis, lis_index, n);
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && (*lis)[i] <= (*lis)[j] + 1)
			{
				(*lis)[i] = (*lis)[j] + 1;
				(*lis_index)[i] = j;
			}
			j++;
		}
		fun_norm(*lis, &max_length, &max_index, i);
		i++;
	}
	return (ft_l(max_index, max_length));
}

int	*array_lis(int *array, int *n_lis, int *lis_index)
{
	int	index;
	int	i;
	int	*res;
	int	temp;

	res = (int *)malloc(sizeof(int) * n_lis[1]);
	if (!res)
		return (NULL);
	i = 0;
	index = n_lis[0];
	while (i < n_lis[1])
	{
		res[i++] = array[index];
		index = lis_index[index];
	}
	i = 0;
	n_lis[1] -= 1;
	while (i < n_lis[1])
	{
		temp = res[i];
		res[i++] = res[n_lis[1]];
		res[n_lis[1]--] = temp;
	}
	return (res);
}

int	*longestincreasingsub(int *array, int n)
{
	int	*lis;
	int	*lis_index;
	int	*n_lis;
	int	*res;

	lis = (int *)malloc(n * sizeof(int));
	lis_index = (int *)malloc(n * sizeof(int));
	if (lis == NULL || lis_index == NULL)
		return (NULL);
	n_lis = max_len(array, n, &lis, &lis_index);
	res = array_lis(array, n_lis, lis_index);
	free(lis);
	free(lis_index);
	free(n_lis);
	return (res);
}
