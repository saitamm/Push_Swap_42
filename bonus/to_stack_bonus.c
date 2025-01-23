/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_stack_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:04:06 by sait-amm          #+#    #+#             */
/*   Updated: 2024/04/03 22:47:51 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_size_stack(t_Node *s)
{
	int	k;

	k = 0;
	while (s)
	{
		k++;
		s = s->next;
	}
	return (k);
}

int	len_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_len(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

void	ft_to_stack(t_Node **s, char **str)
{
	int	val;
	int	i;

	if (*str == NULL || str == NULL)
		norm_error_bonus(s, str);
	i = ft_len(str) - 1;
	while (i >= 0)
	{
		if (ft_checkdigit_bonus(str[i]) == 0 || ft_atoi(str[i], &val, 1) == 0)
			norm_error_bonus(s, str);
		if (ft_checkrepeat_bonus(s, val) == 0)
		{
			*s = ft_add_beg_bonus(s, val);
		}
		else
			norm_error_bonus(s, str);
		i--;
	}
	free_split(str, len_str(str));
}

void	ft_stack_bonus(t_Node **a, char **av, int ac)
{
	char	**str;

	if (ac == 0)
		exit(0);
	if (av[ac][0] == '\0' || *av == NULL)
	{
		write(2, "Error\n", 6);
		free_list(a);
		exit(1);
	}
	while (ac >= 1)
	{
		str = ft_split(av[ac], ' ');
		ft_to_stack(a, str);
		ac--;
	}
}
