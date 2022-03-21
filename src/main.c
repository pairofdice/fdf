/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:14:02 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/21 15:26:22 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

#include <unistd.h>

void	set_left(t_line *line)
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

void draw_line(t_line *line, void *mlx_ptr, void *win_ptr)
{
	// find leftmost point
	// find slope
	// if slope is greater than 1 reverse x, y and take inverse of slope
	// float	m;
	float	dx;
	float	dy;
	float	steps;
	int		i;

	//set_left(line); // maybe do this before this function is called?
	dx = line->b.x - line->a.x;
	dy = line->b.y - line->a.y;
	// m = dy / dx;
	// step = ft_max(ft_abs(dx), ft_abs(dy));
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

int deal_key(int key_nb, void *param)
{
	ft_putnbr(key_nb);
	if (param)
	{}
	ft_putchar('\n');
	return (0);
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

	win_w = 640;
	win_h = 480;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, win_w, win_h, "Machine State");
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
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);

	return (0);
}
