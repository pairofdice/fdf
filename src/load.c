/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:00:22 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/24 20:18:28 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	handle_args(int argc, char **argv, t_context *ctx)
{
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			exit(1);
	}
	else
	{
		ft_putstr("Usage: ./fdf <map>\n");
		exit(1);
	}
	load_map(fd, ctx);
	close(fd);
	return (1);
}

int	load_map(int fd, t_context *ctx)
{
	char	*line;
	char	**words;
	t_point	p;
	t_vec	linevec;

	vec_new(&ctx->map, BUFF_SIZE * 2, sizeof(t_vec));
	p.y = 0;
	while (get_next_line(fd, &line))
	{
		p.x = 0;
		vec_new(&linevec, ft_strlen(line) / 2 + 1, sizeof(t_point));
		words = ft_strsplit(line, ' ');
		while (*words != 0)
		{
			p.z = ft_atoi(*words);
			p.c = p.z;
			vec_push(&linevec, &p);
			p.x++;
			words++;
		}
		if (linevec.len > 0)
			vec_push(&ctx->map, &linevec);
		p.y++;
	}
	return (1);
}
