/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:31:02 by frrusso           #+#    #+#             */
/*   Updated: 2021/12/21 15:51:55 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	i;
	int	fd;

	fd = open("file/notes.txt", O_RDONLY);
	i = 0;
	while (i++ < 10)
		printf("[%s]\n", get_next_line(fd));
	close(fd);
	write(1, "\n", 1);
	fd = open("file/empty", O_RDONLY);
	i = 0;
	while (i++ < 10)
		printf("[%s]\n", get_next_line(fd));
	close(fd);
}
