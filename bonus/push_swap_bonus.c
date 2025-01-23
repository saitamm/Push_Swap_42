/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:18:14 by sait-amm          #+#    #+#             */
/*   Updated: 2024/04/03 22:54:59 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_Node	*a;
	t_Node	*b;
	char	*str;

	a = NULL;
	b = NULL;
	ac--;
	ft_stack_bonus(&a, av, ac);
	while (1)
	{
		str = get_next_line(0);
		if (!str || *str == '\0')
		{
			free(str);
			break ;
		}
		operation_bonus(str, &a, &b);
		free(str);
	}
	if (is_sorted_stack_bonus(a) == 1 && ft_stack_empty_bonus(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(&a);
	return (free_list(&b), 0);
}
