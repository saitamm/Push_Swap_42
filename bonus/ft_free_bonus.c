/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:03:02 by sait-amm          #+#    #+#             */
/*   Updated: 2024/04/03 22:47:16 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_split(char **str, int i)
{
	while (i > 0)
		free(str[--i]);
	free(str);
}

void	free_list(t_Node **head)
{
	t_Node	*temp;

	while ((*head) != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

void	norm_error_bonus(t_Node **a, char **str)
{
	free_list(a);
	free_split(str, len_str(str));
	write(2, "Error\n", 6);
	exit(1);
}

void	ss(t_Node **a, t_Node **b, char *str)
{
	swap_stack(a, NULL);
	swap_stack(b, NULL);
	if (str)
		ft_putstr_fd(str, 1);
}

int	ft_stack_empty_bonus(t_Node *b)
{
	if (b == NULL)
		return (0);
	return (1);
}
