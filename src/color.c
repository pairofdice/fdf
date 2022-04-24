/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:26:45 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/24 23:55:55 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(t_point *color, t_deltas *deltas, t_line *l, t_context *ctx)
{
	t_point	end_color;
	void	(*fn_ptrs[NUM_COLORS])(t_point *color, t_point *p, t_context *ctx);

	fn_ptrs[0] = rainbow_color;
	fn_ptrs[1] = red_blue;
	fn_ptrs[2] = black_white;
	fn_ptrs[3] = rainbow_z_color;
	(*fn_ptrs[ctx->t.color_map])(color, &l->a, ctx);
	(*fn_ptrs[ctx->t.color_map])(&end_color, &l->b, ctx);
	deltas->r = end_color.x - color->x;
	deltas->g = end_color.y - color->y;
	deltas->b = end_color.z - color->z;
}

int	rgb_to_int(t_point c)
{
	return ((int)c.x << 16 | (int)c.y << 8 | (int)c.z);
}
