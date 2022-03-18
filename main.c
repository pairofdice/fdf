/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:14:02 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/18 16:35:00 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

#include <unistd.h>

/* void	ft_putnbr(int n);
void draw_line(int x0, int y0, int x1, int y1)
{
	int		s;
	int		t_step;
	float	error;

	if (x0 > x1)
	{
		s = x1;
		x1 = x0;
		x0 = s;
		s = y1;
		y1 = y0;
		y0 = s;
	}
	s = x0;

	if (y0 < y1)
		t_step = 1;
	else
		t_step = -1;
	error = w / 2;
} */

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
void draw_line(t_line *line, t_context *ctx)
{
	// find leftmost point
	// find slope
	// if slope is greater than 1 reverse x, y and take inverse of slope
	// float	m;
	float	dx;
	float	dy;
	float	steps;
	int		i;

	set_left(line); // maybe do this before this function is called?
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
		mlx_pixel_put(ctx->mlx, ctx->win, line->a.x, line->a.y, 0xFFFFFF);
		line->a.x = line->a.x + dx;
		line->a.y = line->a.y + dy;
		i++;
	}
}
//	dy=m*dx and dx=dy/m

int deal_key(int key_nb, void *param)
{
	ft_putnbr(key_nb);
	ft_putchar('\n');
	return (0);
}

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;


	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 640, 480, "Machine State");
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
	i = 100;
	while (i < 150)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, 200, 0xFFFFFF);
		i++;
	}
	int		mlx_string_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );
	mlx_string_put (mlx_ptr, win_ptr, 300, 300, 0xE3FC03, "How you doin?" );
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);

	return (0);
}
