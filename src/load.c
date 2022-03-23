/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:00:22 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/23 16:59:41 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int load_map(char *filename, t_vec *map)
{
	int		fd;
	char	*line;
	int		r;
	char	**words;
	t_vec	temp;

	fd = open(filename, O_RDONLY);
	vec_new(map, BUFF_SIZE * 2, sizeof(t_vec *));

/* 	r = 1;
	while(r)
	{ */
		vec_new(&temp, BUFF_SIZE * 2, sizeof(int));
		r = get_next_line(fd, &line);
		ft_putstr(line);
		ft_putchar('\n');
		words = ft_strsplit(line, ' ');
		while (*words != 0)
		{
			ft_putstr(*words);
			words++;
		}
		
		vec_strapp(map, line);
/* 
	} */
	return (1);
}