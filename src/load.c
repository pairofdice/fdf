/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:00:22 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/25 19:06:14 by jsaarine         ###   ########.fr       */
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

void	free_array(void **array)
{
	void	**temp;

	temp = *array;
	while (*temp)
		ft_memdel(temp++);
	free(*array);
	*array = NULL;
}

void	do_stuff(t_point *p, char ***words, t_vec *linevec)
{
	p->z = ft_atoi(*(*words));
	p->c = p->z;
	vec_push(linevec, p);
	p->x++;
	(*words)++;
}

int	load_map(int fd, t_context *ctx)
{
	char	*line;
	char	**words;
	char	**temp;
	t_point	p;
	t_vec	linevec;

	vec_new(&ctx->map, BUFF_SIZE * 2, sizeof(t_vec));
	p.y = 0;
	while (get_next_line(fd, &line))
	{
		p.x = 0;
		vec_new(&linevec, ft_strlen(line) / 2 + 1, sizeof(t_point));
		words = ft_strsplit(line, ' ');
		temp = words;
		while (*words != 0)
			do_stuff(&p, &words, &linevec);
		if (linevec.len > 0)
			vec_push(&ctx->map, &linevec);
		p.y++;
		free_array((void *)&temp);
		ft_strdel(&line);
	}
	return (1);
}
