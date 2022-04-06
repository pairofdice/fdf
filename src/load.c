/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:00:22 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/06 16:02:29 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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
			ft_putnbr(p.z);
			vec_push(&linevec, &p);
			words++;
			p.x++;
		}
		vec_push(map, &linevec);
		p.y++;
	}
	// print it out to make sure it worked
	ft_putchar('H');
	close(fd);
	return (1);
}



