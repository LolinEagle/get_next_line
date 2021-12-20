/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:50:59 by frrusso           #+#    #+#             */
/*   Updated: 2021/12/20 18:05:02 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_read(int fd, char *tmp)
{
	read(fd, tmp, 1);
	while (*tmp != '\n')
	{
		tmp++;
		read(fd, tmp, 1);
	}
}

char	*get_next_line(int fd)
{
	size_t	i;
	char	*tmp;
	char	*res;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	ft_read(fd, tmp);
	i = ft_strlen(tmp);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (tmp[i])
	{
		res[i] = tmp[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
