/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:50:59 by frrusso           #+#    #+#             */
/*   Updated: 2021/12/21 14:13:13 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read(int fd, char *tmp)
{
	int	i;

	read(fd, tmp, 1);
	i = 1;
	while (*tmp != '\n' && i > 0)
	{
		tmp++;
		i = read(fd, tmp, 1);
	}
	if (*tmp != '\n')
		i = 0;
	return (i);
}

char	*get_next_line(int fd)
{
	size_t	i;
	char	*tmp;
	char	*res;

	tmp = calloc(sizeof(char), BUFFER_SIZE);
	if (ft_read(fd, tmp) <= 0)
	{
		free(tmp);
		return (NULL);
	}
	res = calloc(sizeof(char), ft_strlen(tmp) + 1);
	i = -1;
	while (tmp[++i])
		res[i] = tmp[i];
	free(tmp);
	return (res);
}
