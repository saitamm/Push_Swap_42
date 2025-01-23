/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:42:34 by sait-amm          #+#    #+#             */
/*   Updated: 2024/04/03 00:21:11 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rr(t_Node **a, t_Node **b, char *str)
{
	rotate(a, NULL);
	rotate(b, NULL);
	if (str)
		ft_putstr_fd(str, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	is_sorted_stack_bonus(t_Node *a)
{
	t_Node	*tmp;

	if (!a)
		return (0);
	tmp = a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	operation_bonus(char *str, t_Node **a, t_Node **b)
{
	if (ft_strcmp(str, "ra\n") == 0)
		rotate(a, NULL);
	else if (ft_strcmp(str, "sa\n") == 0)
		swap_stack(a, NULL);
	else if (ft_strcmp(str, "rra\n") == 0)
		rotate_reverce(a, NULL);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate(b, NULL);
	else if (ft_strcmp(str, "sb\n") == 0)
		swap_stack(b, NULL);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rotate_reverce(b, NULL);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(a, b, NULL);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(a, b, NULL);
	else if (ft_strcmp(str, "pa\n") == 0)
		push(b, a, NULL);
	else if (ft_strcmp(str, "pb\n") == 0)
		push(a, b, NULL);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(a, b, NULL);
	else
		error_bonus(str, a, b);
}

void	error_bonus(char *str, t_Node **a, t_Node **b)
{
	write(2, "Error\n", 6);
	free(str);
	free_list(a);
	free_list(b);
	exit(0);
}
