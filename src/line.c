/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:05:55 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/18 19:44:49 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_points(t_point *p, t_point *deltas, t_point *color_deltas, t_line *line)
{
	*p = line->a;
	line->a.x = (int)line->a.x;
	line->a.y = (int)line->a.y;
	line->b.x = (int)line->b.x;
	line->b.y = (int)line->b.y;
	//d->c = line->b.c - line->a.c;
	deltas->x = line->b.x - line->a.x;
	deltas->y = line->b.y - line->a.y;
	color_deltas->x = line->b_color.r - line->a_color.r;
	color_deltas->y = line->b_color.g - line->a_color.g;
	color_deltas->z = line->b_color.b - line->a_color.b;
}

void	delta_divide(t_point *deltas, t_point *color_deltas, int steps)
{
	deltas->x /= steps;
	deltas->y /= steps;
	//deltas->c /= steps;
	color_deltas->x /= steps;
	color_deltas->y /= steps;
	color_deltas->z /= steps;
}

void	draw_line(t_line *line, t_context *ctx)
{
	t_point			deltas;
	t_point			p;
	int				steps;
	t_point			color_deltas;
	t_color			color;
	int				i;

	set_points(&p, &deltas, &color_deltas, line);
	if (ft_abs(deltas.x) >= ft_abs(deltas.y))
		steps = ft_abs(deltas.x);
	else
		steps = ft_abs(deltas.y);
	delta_divide(&deltas, &color_deltas, steps);
	i = 0;
	if (!neither_point_in_window(line, ctx))
	{
		while (i <= steps)
		{
			if (points_in_window(line, ctx))
				img_pixel_put(&ctx->fb, p.x, p.y, rgb_to_int(color.r + i * color_deltas.x, color.g + i * color_deltas.y, color.b + i * color_deltas.z));
			else
				checked_pixel_put(&ctx->fb, p.x, p.y, rgb_to_int(color.r + i * color_deltas.x, color.g + i * color_deltas.y, color.b + i * color_deltas.z));
			p.x += deltas.x;
			p.y += deltas.y;
			i++;
		}
	}
}
