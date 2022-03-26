/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:00:22 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/26 11:09:16 by jsaarine         ###   ########.fr       */
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
	t_vec	*temp;

	fd = open(filename, O_RDONLY);
	vec_new(map, BUFF_SIZE * 2, sizeof(t_vec));

	r = 1;
	while(r)
	{
		vec_new(&linevec, BUFF_SIZE * 2, sizeof(int));
		r = get_next_line(fd, &line);
		//ft_putstr(line);
		//ft_putchar('\n');
		words = ft_strsplit(line, ' ');
		while (*words != 0)
		{
			k = ft_atoi(*words);
			vec_push(&linevec, &k);
			//ft_putstr(*words);
			//ft_putchar(' ');
			words++;
		}
		//ft_putchar('\n');
		vec_push(map, &linevec);
	}
r = 0;
while (r < (int)map->len)
{
	temp = vec_get(map, r);
	k = 0;
	while (k < (int)temp->len)
	{
		ft_putnbr(*(int *)vec_get(temp, k));
		ft_putchar(' ');
		k++;
	}
		ft_putchar('\n');
	r++;
}
	close(fd);
	return (1);
}
