/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:00:22 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/10 23:46:04 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	handle_args(int argc, char **argv, t_vec *map)
{
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
	}
	else
	{
		ft_putstr("Usage: ./fdf <map>");
		fd = open("maps/10-2.fdf", O_RDONLY);
	}
	load_map(fd, map);
	return (1);
}

int	load_map(int fd, t_vec *map)
{
	char	*line;
	char	**words;
	size_t	k;
	t_point	p;
	t_vec	linevec;
	int		x;
	int		y;

	vec_new(map, BUFF_SIZE * 2, sizeof(t_vec));
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
			words++;
			p.x++;
		}
		vec_push(map, &linevec);
		p.y++;
	}
	close(fd);
	return (1);
}

/*
	t_vec	*line_vec;
	size_t	r;
	r = 0;
	 while (r < map->len)
	{
		line_vec = vec_get(map, r++);
		//line_vec = (t_vec *)map->memory[r].memory;
		// ptr = &map->memory[r];
		//line_vec = (t_vec *) &map->memory[r];
		k = 0;
		while (k < line_vec->len)
		{
			p = *(t_point *)vec_get(line_vec, k++);
		 	// ft_putnbr(p.x);
			// ft_putchar('-');
			// ft_putnbr(p.y);
			// ft_putchar('-');
			ft_putnbr(p.z);
			// ft_putchar('\t');
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
 */
