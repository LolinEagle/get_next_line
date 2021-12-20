/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:31:02 by frrusso           #+#    #+#             */
/*   Updated: 2021/12/20 18:05:18 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	i;
	int	fd;
	
	fd = open("notes.txt", O_RDONLY, O_CREAT);
	i = 0;
	while (i < 9)
	{
		printf("{\n%s\n}\n", get_next_line(fd));
		i++;
	}	
	close(fd);
}
