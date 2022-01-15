/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:50:59 by frrusso           #+#    #+#             */
/*   Updated: 2022/01/12 16:04:31 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_is_nl(const char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] || tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		return (1);
	else
		return (0);
}

char	*ft_realloc_gnl(char *tmp)
{
	int		i;
	char	*buf;

	buf = ft_strdup(tmp);
	free(tmp);
	tmp = ft_calloc(sizeof(char), BUFFER_SIZE + 1 + ft_strlen(buf));
	i = 0;
	while (buf[i++])
	{
		tmp[i] = buf[i];
		tmp++;
	}
	free(buf);
	return (tmp);
}

int	ft_read(int fd, char *tmp)
{
	size_t	i;
	int		r;

	while (1)
	{
		i = BUFFER_SIZE;
		if (read(fd, tmp, 1) <= 0)
		{
			*tmp = '\0';
			return (r);
		}
		while (r > 0 && --i)
		{
			tmp++;
			r = read(fd, tmp, 1);
		}
		*tmp = '\0';
		if (r <= 0)
			return (r);
		else if (ft_is_nl(tmp))
			return (r);
		else
			tmp = ft_realloc_gnl(tmp);
	}
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i + 2);
	return (i + 1);
}

char	*get_next_line(int fd)
{
	static int	i = 1;
	static char	*tmp = 0;
	char		*res;

	if (fd < 0 || BUFFER_SIZE < 1 || i <= 0)
		return (NULL);
	if (!tmp)
		tmp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	i = ft_read(fd, tmp);
	if (i < 0)
	{
		free(tmp);
		return (NULL);
	}
	res = ft_calloc(sizeof(char), ft_strlen_gnl(tmp));
	i = -1;
	while (tmp[++i])
		res[i] = tmp[i];
	return (res);
}
