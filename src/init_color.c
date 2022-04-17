/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:26:45 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/17 23:33:25 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(t_line *line, t_context *ctx)
{
	// TODO
}
/*
	t_color	*a;
	t_color	*b;

	clr->g = 0;
	clr->b = 0;
	clr->g = 125 - sin(((float)line->a.y + ctx->t.frame_n) / 50.0);
	clr *= 80 + deltas.y * (float)i / -100;
	clr->b = 125 + sin(((float)line->a.x + ctx->t.frame_n) / 60.0) * 80
				+ deltas.x * (float)i / -100;
*/

void	set_z_range(t_context *ctx, double i)
{
	if (i < ctx->dims.z_min)
	{
		ctx->dims.z_min = i;
	}
	if (i > ctx->dims.z_max)
	{
		ctx->dims.z_max = i;
	}
}

void	color_spread(t_context *ctx, t_point *p)
{
	p->c -= ctx->dims.z_min;
	p->c /= ctx->dims.z_max ;
}

void	color_range_map(t_context *ctx)
{
	unsigned long	i;
	unsigned long	j;
	t_point			*p;
	t_vec			line;

	i = 0;
	while (i < ctx->map.len)
	{
		line = *(t_vec *)vec_get(&ctx->map, i);
		j = 0;
		while (j < line.len)
		{
			p = (t_point *)vec_get(&line, j);
			color_spread(ctx, p);
			j++;
		}
		i++;
	}
}