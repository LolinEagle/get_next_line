/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:50:59 by frrusso           #+#    #+#             */
/*   Updated: 2022/01/10 17:03:44 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read(int fd, char *tmp)
{
	int	i;
	int	c;

	i = BUFFER_SIZE;
	do
		c = read(fd, tmp, 1);
	while (*tmp++ != '\n' && c > 0 && --i)
		;
	*tmp = '\0';
	return (c);
}

char	*ft_free(char *tmp)
{
	free(tmp);
	return (NULL);
}

char	*get_next_line(int fd)
{
	int		i;
	char	*tmp;
	char	*res;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	tmp = malloc(sizeof(char) * BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	if (ft_read(fd, tmp) <= 0)
		return (ft_free(tmp));
	res = malloc(sizeof(char) * ft_strlen(tmp) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (tmp[++i])
		res[i] = tmp[i];
	res[i] = '\0';
	free(tmp);
	return (res);
}
