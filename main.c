/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:31:02 by frrusso           #+#    #+#             */
/*   Updated: 2022/01/12 17:44:40 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/get_next_line.h"
#include <fcntl.h>// open
#include <stdio.h>// printf

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
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	printf("[Buffer = %i][%s]\n", BUFFER_SIZE, file);
	while (str)
	{
		printf("[GNL%i]%s", ++i, str);
		str = get_next_line(fd);
	}
	printf("[GNL%i]%s[E]\n", ++i, str);
	printf("[GNL%i]%s[O]\n", ++i, str);
	printf("[GNL%i]%s[F]\n", ++i, str);
	close(fd);
	free(str);
	printf("----------------------------------------------------------------\n");
}

int	main(void)
{
	printf("----------------------------------------------------------------\n");
	ft_main("file/notes");
	ft_main("file/notes2");
	ft_main("file/empty");
	ft_main("file/nl");
	ft_main("file/multiple_nlx5");
	// ft_main("file/short_line");
	// ft_main("file/41_no_nl");
	// ft_main("file/41_with_nl");
	// ft_main("file/42_no_nl");
	// ft_main("file/42_with_nl");
	// ft_main("file/43_no_nl");
	// ft_main("file/43_with_nl");
	// ft_main("file/alternate_line_nl_no_nl");
	// ft_main("file/alternate_line_nl_with_nl");
	// ft_main("file/big_line_no_nl");
	// ft_main("file/big_line_with_nl");
	// ft_main("file/multiple_line_no_nl");
	// ft_main("file/multiple_line_with_nl");
}
