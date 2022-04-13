/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:05:55 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/13 20:00:15 by jsaarine         ###   ########.fr       */
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
	unsigned char	color;
	int				i;

	set_points(&p, &deltas, line);
	if (ft_abs(deltas.x) >= ft_abs(deltas.y))
		steps = ft_abs(deltas.x);
	else
		steps = ft_abs(deltas.y);
	delta_divide(&deltas, steps);
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
