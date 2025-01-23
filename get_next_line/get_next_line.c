/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:46:42 by sait-amm          #+#    #+#             */
/*   Updated: 2024/03/21 00:02:03 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str, char *ret)
{
	if (str)
		free(str);
	return (ret);
}

char	*ft_read(int fd, char *line)
{
	char	*buff;
	ssize_t	l;

	l = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (l > 0 && ft_strchar(line) != 1)
	{
		l = read(fd, buff, BUFFER_SIZE);
		if (l == -1)
		{
			free(buff);
			free(line);
			return (NULL);
		}
		buff[l] = '\0';
		if (buff[0] == '\0')
			return (ft_free(buff, line));
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*ft_getline(char *str)
{
	char	*d;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	d = malloc(i + 1);
	if (!d)
		return (ft_free(str, NULL));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		d[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		d[i++] = '\n';
	d[i] = '\0';
	return (d);
}

char	*ft_afterline(char *str)
{
	char	*s;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i] == '\0')
		return (ft_free(str, NULL));
	s = malloc(ft_strlen1(str) - i + 1);
	if (!s)
		return (ft_free(str, NULL));
	while (str[i + k])
	{
		s[k] = str[i + k];
		k++;
	}
	s[k] = '\0';
	free(str);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*stat;
	char		*get;

	if (fd < 0 || fd >= 256 || BUFFER_SIZE <= 0)
		return (NULL);
	stat = ft_read(fd, stat);
	if (!stat || stat[0] == '\0')
		return (ft_free(stat, NULL));
	get = ft_getline(stat);
	if (get[0] == '\0')
	{
		free(get);
		free(stat);
		return (NULL);
	}
	stat = ft_afterline(stat);
	return (get);
}
