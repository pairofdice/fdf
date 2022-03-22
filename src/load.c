/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:00:22 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/21 17:03:49 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int load_map(int argc, char **argv, char *buff)
{
	int		i;
	int		fd;
	ssize_t	chr_count;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	chr_count = read(fd, buff, BUFF + 1);
	buff[chr_count] = '\0';
	close(fd);
	if (chr_count == 0)
		return (0);

	return (1);
}

