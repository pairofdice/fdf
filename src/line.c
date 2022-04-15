/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:05:55 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/15 17:51:50 by jsaarine         ###   ########.fr       */
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

void	delta_divide(t_point *deltas, int steps)
{
	deltas->x /= steps;
	deltas->y /= steps;
	deltas->c /= steps;
}



/*
float	interpolate(t_point *a, t_point *deltas, int i, int steps)
{
	float result;
	result = a->c + i * deltas->c;
	return (result);
}
 */
void	draw_line(t_line *line, t_context *ctx)
{
	t_point			deltas;
	t_point			p;
	int				steps;
	t_color			clr;
	int				i;

	set_points(&p, &deltas, line);
	if (ft_abs(deltas.x) >= ft_abs(deltas.y))
		steps = ft_abs(deltas.x);
	else
		steps = ft_abs(deltas.y);
	delta_divide(&deltas, steps);
	i = 0;
	clr.g = 0;
	clr.b = 0;
	clr.g = 125 - sin(((float)line->a.y + ctx->t.frame_n) / 50.0) * 80 + deltas.y * (float)i / -100;
	 clr.b = 125 + sin(((float)line->a.x + ctx->t.frame_n) / 60.0) * 80 + deltas.x * (float)i / -100;
	if (!neither_point_in_window(line, ctx))
	{
		while (i <= steps)
		{
			checked_pixel_put(&ctx->fb, p.x, p.y, rgb_to_int(p.c * 255, clr.g, clr.b));
			//clr.r = (float)i/(float)steps * line->b.c *20 + (float)(steps-i)/(float)steps * line->b.c *20;
			p.x += deltas.x;
			p.y += deltas.y;
			p.c += deltas.c;
			i++;
		}
	} else if (points_in_window(line, ctx))
	{
		while (i <= steps)
		{
			img_pixel_put(&ctx->fb, p.x, p.y, rgb_to_int(p.c * 255, clr.g, clr.b));
			//clr.r = (float)i/(float)steps * line->b.c *20 + (float)(steps-i)/(float)steps * line->b.c *20;
			p.x += deltas.x;
			p.y += deltas.y;
			p.c += deltas.c;
			i++;
		}
	}
}
