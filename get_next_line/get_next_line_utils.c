/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:16:19 by sait-amm          #+#    #+#             */
/*   Updated: 2024/03/21 00:02:23 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen1(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*b;
	size_t	i;

	i = 0;
	b = malloc(ft_strlen1(s) + 1);
	while (s[i])
	{
		b[i] = s[i];
		i++;
	}
	b[i] = '\0';
	return (b);
}

char	*ft_cpy(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*d;
	size_t	len1;

	i = 0;
	j = 0;
	len1 = ft_strlen1(s1) + ft_strlen1(s2);
	d = (char *)malloc((len1 + 1) * sizeof(char const));
	if (!d)
		return (NULL);
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		d[i + j] = s2[j];
		j++;
	}
	d[i + j] = '\0';
	return (d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*d;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	d = ft_cpy(s1, s2);
	if (s1)
		free(s1);
	return (d);
}

int	ft_strchar(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (-1);
}
