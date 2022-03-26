/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:00:22 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/26 09:43:01 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int load_map(char *filename, t_vec *map)
{
	int		fd;
	char	*line;
	int		r;
	int		k;
	char	**words;
	t_vec	linevec;

	fd = open(filename, O_RDONLY);
	vec_new(map, BUFF_SIZE * 2, sizeof(t_vec *));

	r = 1;
	while(r)
	{
		vec_new(&linevec, BUFF_SIZE * 2, sizeof(int));
		r = get_next_line(fd, &line);
		ft_putstr(line);
		ft_putchar('\n');
		words = ft_strsplit(line, ' ');
		while (*words != 0)
		{
			vec_intapp(&linevec, ft_atoi(*words));
			ft_putstr(*words);
			ft_putchar(' ');
			words++;
		}
		ft_putchar('\n');
		vec_push(map, &linevec);
	}
	r = 0;
	k = 0;
	while (r < (int)map->len)
	{


		while (k < 0/* (map->memory)[r].len */)
		{
			k++;
		}
		// how do I access each int of each line
		printf("%d", map->memory[r][k]);
		r++;
	}
	close(fd);
	return (1);
}
