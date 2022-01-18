/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:33:52 by frrusso           #+#    #+#             */
/*   Updated: 2022/01/17 15:33:55 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_bzero(res, nmemb * size);
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (str[i])
	{
		if (str[i] == (unsigned char) c)
			return ((char *)s + i);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strchr2(const char *s, int c)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (str && str[i])
	{
		if (str[i] == (unsigned char) c)
			return ((char *)s + i);
		i++;
	}
	if (str && str[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}