/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>
#include <stdlib.h>

static char	*read_until_newline(char *buffer)
{
	char	*temp;
	int		bytes_read;
	char	read_buffer[2];

	read_buffer[1] = '\0';
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(0, read_buffer, 1);
		if (bytes_read <= 0)
			break ;
		temp = buffer;
		buffer = ft_strjoin(buffer, read_buffer);
		free(temp);
		if (read_buffer[0] == '\n')
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	buffer = read_until_newline(buffer);
	if (!buffer || ft_strlen(buffer) == 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = buffer;
	buffer = NULL;
	return (line);
}
