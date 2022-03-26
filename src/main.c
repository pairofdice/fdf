/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:14:02 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/25 22:56:57 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "fdf.h"
#include <stdlib.h>

#include <unistd.h>

/* void	set_left(t_line *line)
{
	int	temp;

	if (line->a.x > line->b.x)
	{
		temp = line->a.x;
		line->a.x = line->b.x;
		line->b.x = temp;
		temp = line->a.y;
		line->a.y = line->a.y;
		line->a.y = temp;
	}
}
 */

/* void	draw_pixel(t_point point, t_frame_buffer *fb, unsigned int color)
{
	unsigned long    i;

	i = 4 * ((unsigned int)point.y * fb->width + (unsigned int)point.x);



}
 */
void	draw_line(t_line *line, void *mlx_ptr, void *win_ptr)
{

	float	dx;
	float	dy;
	float	steps;
	int		i;

	dx = (line->b.x - line->a.x);
	dy = (line->b.y - line->a.y);
	if (ft_abs(dx) >= ft_abs(dy))
		steps = ft_abs(dx);
	else
		steps = ft_abs(dy);
	dx = dx / steps;
	dy = dy / steps;
	i = 0;
	while (i < steps)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, line->a.x, line->a.y, 0xFFFFFF);
		line->a.x += dx;
		line->a.y += dy;
		i++;
	}
}

int on_keypress(int key_nb, void *param)
{
	if (key_nb == 53)
		exit (1);
	if (param)
	{}
	return (1);
}

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;
	t_line	line1;
	int mx;
	int my;
	int win_w;
	int win_h;
	t_vec	map;

	win_w = 640;
	win_h = 480;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, win_w, win_h, "Machine State");
	load_map("maps/10-2.fdf", &map);
	i = 100;
	while (i < 150)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 100, i, 0xFFFFFF);
		i++;
	}
	i = 100;
	while (i < 150)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 150, i, 0xFFFFFF);
		i++;
	}
	i = 80;
	while (i < 170)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, 200, 0xFFFFFF);
		i++;
	}
	mx = win_w / 2;
	my = win_h / 2;
	line1 = (t_line){(t_point){mx+5, my+5, 0}, (t_point){mx + 50, my + 50, 0}};
	draw_line(&line1,  mlx_ptr, win_ptr);
	line1 = (t_line){(t_point){mx+5, my-5, 0}, (t_point){mx + 50, my - 50, 0}};
	draw_line(&line1,  mlx_ptr, win_ptr);
	line1 = (t_line){(t_point){mx-5, my+5, 0}, (t_point){mx - 50, my + 50, 0}};
	draw_line(&line1,  mlx_ptr, win_ptr);
	line1 = (t_line){(t_point){mx-5, my-5, 0}, (t_point){mx - 50, my - 50, 0}};
	draw_line(&line1,  mlx_ptr, win_ptr);

	line1 = (t_line){(t_point){mx+5, my+5, 0}, (t_point){mx + 100, my + 50, 0}};
	draw_line(&line1,  mlx_ptr, win_ptr);
	line1 = (t_line){(t_point){mx+5, my-5, 0}, (t_point){mx + 50, my - 100, 0}};
	draw_line(&line1,  mlx_ptr, win_ptr);
	line1 = (t_line){(t_point){mx-5, my+5, 0}, (t_point){mx - 100, my + 50, 0}};
	draw_line(&line1,  mlx_ptr, win_ptr);
	line1 = (t_line){(t_point){mx-5, my-5, 0}, (t_point){mx - 50, my - 100, 0}};
	draw_line(&line1,  mlx_ptr, win_ptr);

	line1 = (t_line){(t_point){mx+5, my+5, 0}, (t_point){mx + 50, my + 100, 0}};
	draw_line(&line1,  mlx_ptr, win_ptr);
	line1 = (t_line){(t_point){mx+5, my-5, 0}, (t_point){mx + 100, my - 50, 0}};
	draw_line(&line1,  mlx_ptr, win_ptr);
	line1 = (t_line){(t_point){mx-5, my+5, 0}, (t_point){mx - 50, my + 100, 0}};
	draw_line(&line1,  mlx_ptr, win_ptr);
	line1 = (t_line){(t_point){mx-5, my-5, 0}, (t_point){mx - 100, my - 50, 0}};
	draw_line(&line1,  mlx_ptr, win_ptr);



	//int		mlx_string_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );
	mlx_string_put (mlx_ptr, win_ptr, 300, 300, 0xE3FC03, "How you doin?" );
	mlx_key_hook(win_ptr, on_keypress, (void *)0);
	mlx_loop(mlx_ptr);

	return (0);
}

/*
t_img_state	img;

	void		*mlx_ptr;
	void		*win_ptr;
	int			i;

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);


	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 640, 480, "Machine State");


	img.img = mlx_new_image(mlx_ptr, 1920, 1080);


	int		mlx_string_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );
	mlx_string_put (mlx_ptr, win_ptr, 300, 300, 0xE3FC03, "How you doin?" );
	mlx_key_hook(win_ptr, on_keypress, (void *)0);
	mlx_loop(mlx_ptr);




	t_line    line1;
	int mx;
	int my;
	int win_w;
	int win_h;
	win_w = 640;
	win_h = 480;

	i = 100;
	while (i < 150)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 100, i, 0xFFFFFF);
		i++;
	}
	mx = win_w / 2;
	my = win_h / 2;
	line1 = (t_line){(t_point){mx+5, my+5, 0}, (t_point){mx + 50, my + 50, 0}};
	draw_line(&line1,  mlx_ptr, win_ptr);
	line1 = (t_line){(t_point){mx+5, my-5, 0}, (t_point){mx + 50, my - 50, 0}};
	draw_line(&line1,  mlx_ptr, win_ptr);
	line1 = (t_line){(t_point){mx-5, my+5, 0}, (t_point){mx - 50, my + 50, 0}};
	draw_line(&line1,  mlx_ptr, win_ptr);
	line1 = (t_line){(t_point){mx-5, my-5, 0}, (t_point){mx - 50, my - 50, 0}};
	draw_line(&line1,  mlx_ptr, win_ptr);

	//int        mlx_string_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );
	mlx_string_put (mlx_ptr, win_ptr, 300, 300, 0xE3FC03, "How you doin?" );
	mlx_key_hook(win_ptr, on_keypress, (void *)0);
	mlx_loop(mlx_ptr);
	return (0); */
