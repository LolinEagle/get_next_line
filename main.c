/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:31:02 by frrusso           #+#    #+#             */
/*   Updated: 2022/01/10 17:09:05 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_main(char *file)
{
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while (str && str[ft_strlen(str) - 1] == '\n')
	{
		printf("%s", str);
		str = get_next_line(fd);
	}
	printf("%s", str);
	close(fd);
	free(str);
	printf("\n---------------------------------------------------------------\n");
}

int	main(void)
{
	ft_main("file/notes.txt");
	ft_main("file/empty");
	ft_main("file/41_no_nl");
	ft_main("file/41_with_nl");
	ft_main("file/42_no_nl");
	ft_main("file/42_with_nl");
	ft_main("file/43_no_nl");
	ft_main("file/43_with_nl");
}
