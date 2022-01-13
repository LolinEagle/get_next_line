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

int	ft_read(int fd, char *tmp)
{
	unsigned int	i;
	int				r;

	if (BUFFER_SIZE < 4294967295)
		i = BUFFER_SIZE;
	else
		i = 4294967295;
	r = read(fd, tmp, 1);
	if (r <= 0)
	{
		*tmp = '\0';
		return (r);
	}
	while (*tmp != '\n' && r > 0 && --i)
	{
		tmp++;
		r = read(fd, tmp, 1);
	}
	tmp++;
	*tmp = '\0';
	return (r);
}

char	*ft_free(char *tmp)
{
	free(tmp);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static int	eof = 0;
	int			i;
	char		*tmp;
	char		*res;

	if (fd < 0 || BUFFER_SIZE < 1 || eof)
	{
		eof = 0;
		return (NULL);
	}
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	i = ft_read(fd, tmp);
	if (i <= 0)
		eof = 1;
	if (i < 0)
		return (ft_free(tmp));
	res = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
	i = -1;
	while (tmp[++i])
		res[i] = tmp[i];
	res[i] = '\0';
	free(tmp);
	return (res);
}
