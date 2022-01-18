/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:33:15 by frrusso           #+#    #+#             */
/*   Updated: 2022/01/17 15:33:19 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	res = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	res = NULL;
	return (res);
}

long int	ft_read(int fd, char **buf, char **res)
{	
	int			i;
	long int	r;

	if (!(*buf))
		return (-1);
	r = read(fd, buf[0], 1);
	if (r <= 0)
		return (r);
	while (r > 0 && !ft_strchr(res[0], '\n'))
	{
		i = 0;
		while (r > 0 && ++i < BUFFER_SIZE)
			r = read(fd, buf[0], 1);
		buf[0][ft_strlen(buf[0]) + 1] = '\0';
		res[0] = ft_strjoin_gnl(res[0], buf[0]);
		//printf("r=%li buf[0][i]=%i res[0]=%s\n", r, buf[0][r], res[0]);
	}
	return (r);
}

void	ft_setline(char **res, char **tail)
{
	char	*eol;

	eol = ft_strchr2(res[0], '\n');
	free(*tail);
	if (eol)
	{
		*tail = ft_strdup(eol + 1);
		eol[1] = '\0';
	}
	else
		*tail = NULL;
}

char	*ft_free(char *buf, char *fd_buf, char *res)
{
	free(fd_buf);
	free(buf);
	free(res);
	return (NULL);
}

char	*get_next_line(int fd)
{
	long int	i;
	static char	*fd_buf[256];
	char		*buf;
	char		*res;

	if (fd < 0 || fd >= 255 || BUFFER_SIZE < 1)
		return (NULL);
	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	fd_buf[fd] = ft_strjoin_gnl(fd_buf[fd], "\0");
	res = ft_strdup(fd_buf[fd]);
	i = ft_read(fd, &buf, &res);
	if (i < 0 || !buf)
		return (ft_free(buf, fd_buf[fd], res));
	ft_setline(&res, &fd_buf[fd]);
	if (i == 0 && !fd_buf[fd] && res)//res[0] == '\0')
	{
		free(res);
		res = NULL;
	}
	free(buf);
	return (res);
}
