/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:14:27 by mtavares          #+#    #+#             */
/*   Updated: 2022/04/19 18:30:23 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	int			byte_read;
	static char	buff[FOPEN_MAX][BUFFER_SIZE];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	byte_read = 1;
	while (byte_read)
	{
		if (!buff[fd][0])
			byte_read = read(fd, buff[fd], BUFFER_SIZE);
		if (byte_read > 0)
			line = ft_get_line(buff[fd], line);
		if (ft_checknl(buff[fd]) || byte_read < 1)
			return (line);
	}
	return (line);
}
