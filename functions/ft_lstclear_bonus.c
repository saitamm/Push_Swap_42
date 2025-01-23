/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:06:26 by sait-amm          #+#    #+#             */
/*   Updated: 2024/02/22 10:45:52 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(Node **lst, void (*del)(void *))
{
	Node	*k;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		k = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(k);
	}
	*lst = NULL;
}
