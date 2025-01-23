/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:28:59 by sait-amm          #+#    #+#             */
/*   Updated: 2024/03/31 23:54:19 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		norm_error(s, str);
	i = ft_len(str) - 1;
	while (i >= 0)
	{
		if (ft_checkdigit(str[i]) == 0 || ft_atoi(str[i], &val, 1) == 0)
			norm_error(s, str);
		if (ft_checkrepeat(s, val) == 0)
			*s = ft_add_beg(s, val);
		else
			norm_error(s, str);
		i--;
	}
	free_split(str, len_str(str));
}

void	ft_stack(t_Node **a, char **av, int ac)
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
