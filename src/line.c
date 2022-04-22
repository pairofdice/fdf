/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:05:55 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/22 18:16:31 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_points(t_point *p, t_point *deltas, t_line *line)
{
	*p = line->a;
	line->a.x = (int)line->a.x;
	line->a.y = (int)line->a.y;
	line->b.x = (int)line->b.x;
	line->b.y = (int)line->b.y;
	deltas->x = line->b.x - line->a.x;
	deltas->y = line->b.y - line->a.y;
	deltas->c = line->b.c - line->a.c;
}

void	delta_divide(t_point *deltas, int steps)
{
	deltas->x /= steps;
	deltas->y /= steps;
	deltas->c /= steps;
}

void	delta_increment(t_point *p, t_point *deltas)
{
	p->x += deltas->x;
	p->y += deltas->y;
	p->c += deltas->c;
}

void	draw_line(t_line *line, t_context *ctx)
{
	t_point	deltas;
	t_point	p;
	int		steps;
	t_point	color;
	int		i;

	set_points(&p, &deltas, line);
	if (ft_abs(deltas.x) >= ft_abs(deltas.y))
		steps = ft_abs(deltas.x);
	else
		steps = ft_abs(deltas.y);
	delta_divide(&deltas, steps);
	i = 0;
	if (!neither_point_in_window(line, ctx))
	{
		while (i++ <= steps)
		{
			set_color(&color, p, ctx);
			if (points_in_window(line, ctx))
				img_pixel_put(&ctx->fb, p.x, p.y, rgb_to_int(color));
			else
				checked_pixel_put(&ctx->fb, p.x, p.y, rgb_to_int(color));
			delta_increment(&p, &deltas);
		}
	}
}
