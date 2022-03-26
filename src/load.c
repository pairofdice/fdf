/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:00:22 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/26 11:47:30 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int load_map(char *filename, t_vec *map)
{
	int		fd;
	char	*line;
	size_t	r;
	size_t	k;
	char	**words;
	t_vec	linevec;
	t_vec	*line_vec;

	fd = open(filename, O_RDONLY);
	vec_new(map, BUFF_SIZE * 2, sizeof(t_vec));
	r = 1;
	while(r)
	{
		vec_new(&linevec, BUFF_SIZE * 2, sizeof(int));
		r = get_next_line(fd, &line);
		words = ft_strsplit(line, ' ');
		while (*words != 0)
		{
			k = ft_atoi(*words);
			vec_push(&linevec, &k);
			words++;
		}
		if (r)
			vec_push(map, &linevec);
	}
	// print it out to make sure it worked
	r = 0;
	while (r < map->len)
	{
		line_vec = vec_get(map, r);
		k = 0;
		while (k < line_vec->len)
		{
			ft_putnbr(*(int *)vec_get(line_vec, k));
			ft_putchar(' ');
			k++;
		}
			ft_putchar('\n');
		r++;
	}
	close(fd);
	return (1);
}
