/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:05:55 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/18 08:29:51 by jsaarine         ###   ########.fr       */
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

void	draw_line(t_line *line, t_context *ctx)
{
	t_point			deltas;
	t_point			p;
	int				steps;
	t_color			color_deltas;
	int				i;

	set_points(&p, &deltas, line);
	if (ft_abs(deltas.x) >= ft_abs(deltas.y))
		steps = ft_abs(deltas.x);
	else
		steps = ft_abs(deltas.y);
	delta_divide(&deltas, steps);
	i = 0;
	if (!neither_point_in_window(line, ctx))
	{
		// if BOTH points in window do unchecked put
		// else ...
		while (i <= steps)
		{
			checked_pixel_put(&ctx->fb, p.x, p.y,
				rgb_to_int(p.c * 255, clr.g, clr.b));
			p.x += deltas.x;
			p.y += deltas.y;
			i++;
		}
	}
}
