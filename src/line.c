/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:05:55 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/15 11:07:26 by jsaarine         ###   ########.fr       */
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


void color_spread(t_context *ctx, t_point *p)
{
	//printf(" %4.2f, ", p->c);
	p->c -= ctx->dims.z_min;/*
	if (ctx->dims.z_max != 0) */
	p->c /= ctx->dims.z_max ;
	//p->c -= 1;
	//printf("%4.2f |", p->c);
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
	clr.g = 125 - sin(((float)line->a.y + ctx->t.frame_n) / 50.0) * 80 + deltas.y * (float)i / -100;
	clr.b = 125 + sin(((float)line->a.x + ctx->t.frame_n) / 60.0) * 80 + deltas.x * (float)i / -100;
	while (i <= steps)
	{

		//clr.r = (float)i/(float)steps * line->b.c *20 + (float)(steps-i)/(float)steps * line->b.c *20;
		checked_pixel_put(&ctx->fb, p.x, p.y, rgb_to_int(p.c, clr.g, clr.b));
		p.x += deltas.x;
		p.y += deltas.y;
		p.c += deltas.c;
		i++;
	}
}
