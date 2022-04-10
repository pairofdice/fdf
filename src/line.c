/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:05:55 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/10 22:55:22 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_points(t_point *p, t_point *d, t_line *line)
{
	*p = line->a;
	d->c = (line->b.c - line->a.c);
	d->x = (line->b.x - line->a.x);
	d->y = (line->b.y - line->a.y);
}

void	draw_line(t_line *line, t_context *ctx)
{
	t_point			d;
	t_point			p;
	float			steps;
	unsigned char	color;
	int				i;

	set_points(&p, &d, line);
	if (ft_abs(d.x) > ft_abs(d.y))
		steps = ft_abs(d.x);
	else
		steps = ft_abs(d.y);
	d.x = d.x / steps;
	d.y = d.y / steps;
	d.c = d.c / steps;
	i = 0;
	while (i < steps)
	{
		color = line->a.c * 25.0 + d.c * (float)i * 25.0;
		checked_pixel_put(&ctx->fb, round(p.x), round(p.y),
			rgb_to_int(color, 125 - sin(((float)line->a.y + ctx->t.frame_n)
					/ 50.0) * 80 + d.y * (float)i / -100,
				125 + sin(((float)line->a.x + ctx->t.frame_n) / 60.0) * 80
				+ d.x * (float)i / -100));
		p.x += d.x;
		p.y += d.y;
		i++;
	}
}
