/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:10:11 by sait-amm          #+#    #+#             */
/*   Updated: 2024/03/24 15:57:55 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **str, int i)
{
	while (i > 0)
	{
		free(str[--i]);
	}
	free(str);
}

void	free_array(t_array *l)
{
	free(l->res);
	free(l->str);
	free(l);
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
