/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:16:06 by sait-amm          #+#    #+#             */
/*   Updated: 2024/04/03 22:49:23 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_Node	*a;
	t_Node	*b;
	t_array	*l;

	a = NULL;
	b = NULL;
	l = NULL;
	ft_stack(&a, av, --ac);
	if (is_sorted_stack(a) == 1)
		return (free_list(&a), 0);
	if (ft_size_stack(a) <= 5)
		sort_inf_5(&a, &b, ft_size_stack(a));
	else
	{
		l = malloc(sizeof(t_array));
		if (!l)
			return (0);
		initial_array(a, ft_size_stack(a), l);
		ft_push_to_b(&a, &b, l);
		ft_sort_a(&a, &b);
		free_array(l);
	}
	free_list(&a);
	free_list(&b);
	return (0);
}
