/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:26:45 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/18 20:02:31 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(t_line *line)
{
	// TODO
	line->a_color.r = 255;
	line->a_color.g = 200;
	line->a_color.b = 200;
	line->b_color.r = 0;
	line->b_color.g = 90;
	line->b_color.b = 90;
	if (ctx)
	{}
}
/*

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
		ctx->dims.z_min = i;
	if (i > ctx->dims.z_max)
		ctx->dims.z_max = i;
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

			// Needs to get redone
			//set_color(&line, ctx); // maybe here? Definitely don't set color every frame
			j++;
		}
		i++;
	}
}
