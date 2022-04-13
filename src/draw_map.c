/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:01:21 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/13 19:51:51 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	transform_line(t_point p1, t_point p2, t_context *ctx)
{
	t_line	line;

	do_transforms(&p1, ctx);
	do_transforms(&p2, ctx);
	line.a = p1;
	line.b = p2;
	draw_line(&line, ctx);
}

static void	draw_horiz_line(t_vec *map_line, int i, t_context *ctx)
{
	t_point	*p1;
	t_point	*p2;

	p1 = (t_point *) vec_get(map_line, i);
	p2 = (t_point *) vec_get(map_line, i + 1);
	if (p1 && p2)
		transform_line(*p1, *p2, ctx);
}

static void	draw_vert_line(t_vec *map_line,
			t_vec *map_next, int i, t_context *ctx)
{
	t_point	*p1;
	t_point	*p2;

	p1 = (t_point *) vec_get(map_line, i);
	p2 = (t_point *) vec_get(map_next, i);
	if (p1 && p2)
		transform_line(*p1, *p2, ctx);
}

void	draw_map(t_context *ctx)
{
	int		x;
	int		y;
	t_vec	*map_line;
	t_vec	*map_next;

	y = 0;
	while (y < ctx->map.len - 1)
	{
		map_line = (t_vec *)vec_get(&ctx->map, y);
		map_next = (t_vec *)vec_get(&ctx->map, y + 1);
		x = 0;
		while (x < map_line->len - 1)
		{
			draw_horiz_line(map_line, x, ctx);
			draw_vert_line(map_line, map_next, x, ctx);
			if (x == map_line->len - 2)
				draw_vert_line(map_line, map_next, x + 1, ctx);
			if (y == ctx->map.len - 2)
				draw_horiz_line((t_vec *)vec_get(&ctx->map, y + 1), x, ctx);
			x++;
		}
		y++;
	}
}
