/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:14:02 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/03 12:40:30 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../minilibx/mlx.h" */
#include "fdf.h"
#include <stdlib.h>

#include <unistd.h>

// ILLEGAL!!!!
#include <stdio.h>
#include <math.h>

int clamp(int nb, int boundary)
{
	if (nb > boundary)
		nb = boundary;
	return (nb);
}
void	max_dims(t_vec *map, t_point *max)
{
	int i;
	t_vec line;

	i = 0;
	max->x = map->len;
	max->y = 0;
	while (i < map->len)
	{
		line = *(t_vec *)vec_get(map, i);

		 if ( max->y <  line.len)
		 	max->y = line.len;
		i++;
	}
}

int on_keypress(int key_nb, void *param)
{
	ft_putnbr(key_nb);
	ft_putchar('\n');
	if (key_nb == 53 || key_nb == 65307)
		exit (1);
	if (param)
	{}
	return (1);
}


/* int		on_mousepress(int button,int x,int y,void *param)
{
	return (1);
} */

void print_map(t_vec * map)
{
	t_vec	*line_vec;
	size_t	r;
	r = 0;
	size_t k;
	t_point p;
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

			printf("[%4.1f %4.1f %4.1f]", p.x, p.y, p.z);
			/*
			ft_putnbr(p.x);
			ft_putchar('-');
			ft_putnbr(p.y);
			ft_putchar('-');
			ft_putnbr(p.z);
			ft_putchar('\t');
			ft_putchar(' '); */
		}
		printf("\n");
	}
}

int main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
 	int		i;
	 t_line	line1;
 	int mx;
	int my;
	int win_w;
	int win_h;
	t_vec	map;
	t_frame_buffer fb;
	int fd;

	win_w = 900;
	win_h = 900;
	mlx = mlx_init();
	fb.img = mlx_new_image(mlx, win_w, win_h);
	fb.data = mlx_get_data_addr(fb.img, &fb.bits_per_pixel, &fb.line_length, &fb.endian);
	win = mlx_new_window(mlx, win_w, win_h, "Machine State");
	art_project(&fb, win_w, win_h);

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = open("maps/10-2.fdf", O_RDONLY);
	load_map(fd, &map);
	//print_map(&map);
	t_point max = {0, 0, 0};
	max_dims(&map, &max);


	model_to_world(&map, &max);
	//rotate(&map, -0.785);
	isometric(&map);
	world_to_view(&map, win_w, win_h);
	draw_map(&fb, &map, win_w, win_h, &max);
	//print_map(&map);


 	mx = win_w / 2;
	my = win_h / 2;

	mlx_put_image_to_window(mlx, win, fb.img, 0, 0);


	//int		mlx_string_put ( void *mlx, void *win, int x, int y, int color, char *string );
	mlx_key_hook(win, on_keypress, (void *)0);
	//mlx_string_put (mlx, win, win_w/2 - 64, 200, 0xFFFFFF, "How you doin?" );
	mlx_loop(mlx);

	return (0);
}
