/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:28:54 by sait-amm          #+#    #+#             */
/*   Updated: 2024/03/25 00:58:18 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef INT_MAX

#  define INT_MAX 2147483647

# endif

# ifndef INT_MIN

#  define INT_MIN -2147483648

# endif

size_t	ft_strlen(const char *str);
long	ft_atoi(const char *str, int *nb, int flag);
char	**ft_split(const char *str, char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);

#endif