/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:31:02 by frrusso           #+#    #+#             */
/*   Updated: 2021/12/21 13:54:22 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	i;
	int	fd;

	fd = open("file/notes.txt", O_RDONLY, O_CREAT);
	i = -1;
	while (i++ < 8)
		printf("[%s]\n", get_next_line(fd));
	close(fd);
	fd = open("file/empty", O_RDONLY, O_CREAT);
	i = -1;
	while (i++ < 8)
		printf("(%s)\n", get_next_line(fd));
	close(fd);
}
