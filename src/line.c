/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:05:55 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/13 15:52:35 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_points(t_point *p, t_point *d, t_line *line)
{
	*p = line->a;
	line->a.x = (int)line->a.x;
	line->a.y = (int)line->a.y;
	line->b.x = (int)line->b.x;
	line->b.y = (int)line->b.y;
	d->c = line->b.c - line->a.c;
	d->x = line->b.x - line->a.x;
	d->y = line->b.y - line->a.y;
}

void	draw_line(t_line *line, t_context *ctx)
{
	t_point			deltas;
	t_point			p;
	double		steps;
	unsigned char	color;
	int				i;

	set_points(&p, &deltas, line);
	if (ft_abs(deltas.x) >= ft_abs(deltas.y))
		steps = ft_abs(deltas.x);
	else
		steps = ft_abs(deltas.y);
	deltas.x /= steps;
	deltas.y /= steps;
	deltas.c /= steps;
	i = 0;
	while (i <= steps)
	{
		color = line->a.c * 25.0 + deltas.c * (float)i * 25.0;
		checked_pixel_put(&ctx->fb, floor(p.x), floor(p.y), 
			rgb_to_int(color, 125 - sin(((float)line->a.y + ctx->t.frame_n)
					/ 50.0) * 80 + deltas.y * (float)i / -100,
				125 + sin(((float)line->a.x + ctx->t.frame_n) / 60.0) * 80
				+ deltas.x * (float)i / -100));
		p.x += deltas.x;
		p.y += deltas.y;
		i++;
	}
}
/* 

float	dx;
float	dy;
int		step;
float	x;
float	y

dx = line.x1 - line.x0;
dy = line.y1 - line.y0;
x = line.x0;
y = line.y0;

if (ft_abs(dx) >= ft_abs(dy))
	step = ft_abs(dx);
else
	step = ft_abs(dy);

dx = dx / step;
dy = dy / step;

while (step >= 0)
{
	img_pixel_put(data, x, y, color_gradient(c0, c1, step));
	c0 = color_gradient(c0, c1, step);
	x = x + dx;
	y = y + dy;
	step--;
}
return (1);  */
