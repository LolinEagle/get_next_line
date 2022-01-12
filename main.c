/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:31:02 by frrusso           #+#    #+#             */
/*   Updated: 2022/01/12 16:30:50 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_putstr(char *s)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i])
			write(1, &s[i++], 1);
	}
}

void	ft_main(char *file)
{
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		printf("FOLDER ERROR");
	str = get_next_line(fd);
	printf("~[%s][fd = %i]\n", file, fd);
	while (str)
	{
		printf("~%s", str);
		str = get_next_line(fd);
	}
	printf("[End Of File]%s\n", str);
	close(fd);
	free(str);
	printf("----------------------------------------------------------------\n");
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
		i = 1;
	else
		i = 0;
	printf("----------------------------------------------------------------\n");
	ft_main("file/notes");
	ft_main("file/notes2");
	ft_main("file/empty");
	if (i)
	{
		ft_main("file/41_no_nl");
		ft_main("file/41_with_nl");
		ft_main("file/42_no_nl");
		ft_main("file/42_with_nl");
		ft_main("file/43_no_nl");
		ft_main("file/43_with_nl");
		ft_main("file/alternate_line_nl_no_nl");
		ft_main("file/alternate_line_nl_with_nl");
		ft_main("file/multiple_line_no_nl");
		ft_main("file/multiple_line_with_nl");
		ft_main("file/multiple_nlx5");
		ft_main("file/nl");
	}
}
