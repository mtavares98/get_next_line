/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:14:27 by mtavares          #+#    #+#             */
/*   Updated: 2022/04/19 17:42:19 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			byte_read;
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	byte_read = 1;
	while (1)
	{
		if (!buff[0])
			byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read > 0)
			line = ft_get_line(buff, line);
		if (byte_read < 1 || ft_checknl(buff))
			break ;
	}
	return (line);
}
