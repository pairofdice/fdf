/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:14:02 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/22 12:53:22 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

#include <unistd.h>

void draw_line(t_line *line, void *mlx_ptr, void *win_ptr)
{
	float	dx;
	float	dy;
	float	steps;
	int		i;

	dx = line->b.x - line->a.x;
	dy = line->b.y - line->a.y;
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
		line->a.x = line->a.x + dx;
		line->a.y = line->a.y + dy;
		i++;
	}
}

int	on_keypress(int key_nb)
{
	if (key_nb = 53)
		exit (1);
	return (1);
}

int main()
{
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
	return (0);
}
