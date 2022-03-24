/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:00:22 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/24 15:35:13 by jsaarine         ###   ########.fr       */
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
	t_vec	temp;

	fd = open(filename, O_RDONLY);
	vec_new(map, BUFF_SIZE * 2, sizeof(t_vec *));

	r = 1;
	while(r)
	{
		vec_new(&temp, BUFF_SIZE * 2, sizeof(int));
		r = get_next_line(fd, &line);
		ft_putstr(line);
		ft_putchar('\n');
		words = ft_strsplit(line, ' ');
		while (*words != 0)
		{
			vec_intapp(&temp, ft_atoi(*words));
			ft_putstr(*words);
			ft_putchar(' ');
			words++;
		}
		ft_putchar('\n');
		vec_ptrapp(map, &temp);
	} 
	r = 0;
	k = 0;
	while (r < (int)map->len)
	{
		t_vec temp;
		temp = *(&map->memory[r]);
		while (k < map->memory[0]->len)
		{
			k++;
		}

		r++;
	}
	close(fd);
	return (1);
}