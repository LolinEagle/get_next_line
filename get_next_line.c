/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:50:59 by frrusso           #+#    #+#             */
/*   Updated: 2021/12/20 14:23:00 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	int		n;
	char	*res;
	
	n = read(fd, )
	return (res);
}
/*
• Your function should return the line that has just been read. If there is nothing
else to read or if an error has occurred it should return NULL.

• Your read must use the BUFFER_SIZE defined during compilation to read from
a file or from stdin. This value will be modified during the evaluation for testing
purposes.

• In the header file get_next_line.h you must have at least the prototype of the
function get_next_line.

Does your function still work if the BUFFER_SIZE value is 9999? And
if the BUFFER_SIZE value is 1? And 10000000?

• We consider that get_next_line has undefined behavior if, between two calls, the
same file descriptor switches to a different file before reading everything from the
first fd.+

• Finally we consider that get_next_line has undefined behavior when reading from
a binary file. However, if you wish, you can make this behavior coherent.

• Important: The returned line should include the ’\n’, except if you have reached
the end of file and there is no ’\n’.
*/
