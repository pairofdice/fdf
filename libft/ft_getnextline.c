/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:49:28 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/25 14:04:28 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*
	Copy from storage to line for output.
	Move contents of storage up.
	If this is the last line, set storage to 0
 */
static void	output(t_vec *storage, char **line)
{
	size_t	len;

	*line = ft_strdup(storage->memory);
	len = ft_strlen(storage->memory);
	if (storage->len - (len + 1))
	{
		ft_memcpy(storage->memory,
			&storage->memory[len + 1],
			storage->len - len + 1);
		storage->len -= len + 1;
	}
	else
		storage->len = 0;
}

/*
	vec_strapp appends our read buffer into our storage vector.
	We search for a newline and if found set it to be a terminator.
	If we didn't find a newline and we didn't read anything and
	we have something in storage, it means this is the last line of the
	file and our storage isn't properly terminated so we push a \0 to the end
 */
static int	read_into_storage(t_vec *storage, const int fd)
{
	ssize_t	ret;
	char	*hodl;
	char	buffer[BUFF_SIZE + 1];

	ret = read(fd, buffer, BUFF_SIZE);
	if (ret < 0)
		return (0);
	hodl = NULL;
	while (ret > 0)
	{
		buffer[ret] = '\0';
		vec_strapp(storage, buffer);
		hodl = ft_strnchr(storage->memory, '\n', storage->len);
		if (hodl)
		{
			*hodl = '\0';
			break ;
		}
		ret = read(fd, buffer, BUFF_SIZE);
	}
	if (!hodl && ret == 0 && storage->len > 0)
		vec_push(storage, "\0");
	return (ret);
}

/*
	First we check if we already read another line into storage turn it
	into a string and output.
	After reading we check if our storage is empty and if so, free, else output
*/
int	get_next_line(const int fd, char **line)
{
	static t_vec	fd_seen[MAX_FD];
	char			*hodl;

	if (fd < 0 || fd >= MAX_FD)
		return (-1);
	if (!fd_seen[fd].memory)
		vec_new(&fd_seen[fd], BUFF_SIZE * 2, 1);
	hodl = ft_strnchr(fd_seen[fd].memory, '\n', fd_seen[fd].len);
	if (hodl)
	{
		*hodl = '\0';
		output(&fd_seen[fd], line);
		return (1);
	}
	if (read_into_storage(&fd_seen[fd], fd) < 0)
		return (-1);
	if (fd_seen[fd].len <= 0)
	{
		vec_free(&fd_seen[fd]);
		return (0);
	}
	output(&fd_seen[fd], line);
	return (1);
}
