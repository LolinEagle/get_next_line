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

#include <stdio.h>

int	ft_is_nl(const char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
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
	i = -1;
	while (buf[++i])
		tmp[i] = buf[i];
	free(buf);
	return (tmp);
}

int	ft_read(int fd, char *tmp)
{
	size_t	i;
	int		r;

	if (ft_is_nl(tmp))
		return (1);
	while (1)
	{
		i = 0;
		r = read(fd, tmp, 1);
		if (r <= 0)
			return (r);
		//printf("|%s", tmp);
		while (r > 0 && ++i < BUFFER_SIZE)
			r = read(fd, tmp + i, 1);
		//printf("|%s i=%zu\n", tmp, i);
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
	int			i;
	static int	r = 1;
	static char	*tmp = 0;
	char		*res;

	printf("start{r=%i tmp=%s}\n", r, tmp);
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (tmp && !r)
	{
		r = 1;
		// free(tmp);
		return (NULL);
	}
	if (!tmp)
		tmp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	r = ft_read(fd, tmp);
	if (r < 0)
	{
		// free(tmp);
		return (NULL);
	}
	printf("->%zu\n", ft_strlen_gnl(tmp));
	if (ft_strlen_gnl(tmp) > 1)
		res = ft_calloc(sizeof(char), ft_strlen_gnl(tmp));
	else
		return (NULL);
	i = -1;
	while (*tmp)
	{
		//printf("tmp[i]=%c}", tmp[i]);
		res[++i] = *tmp;
		tmp++;
	}
	printf("return{i=%i r=%i tmp=%s res=%s}", i, r, tmp, res);
	return (res);
}
