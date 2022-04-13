/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:01:21 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/13 17:23:16 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_connection(t_point p1, t_point p2, t_line line, t_context *ctx)
{
	do_transforms(&p1, ctx);
	do_transforms(&p2, ctx);
	line.a = p1;
	line.b = p2;
	draw_line(&line, ctx);
}

void	draw_horiz_line(t_vec *map_line, int i, t_context *ctx)
{
	t_point	*p1;
	t_point	*p2;
	t_line	line;

	p1 = (t_point *) vec_get(map_line, i);
	p2 = (t_point *) vec_get(map_line, i + 1);
	if (p1 && p2)
		draw_connection(*p1, *p2, line, ctx);
}

void	draw_vert_line(t_vec *map_line,
			t_vec *map_next, int i, t_context *ctx)
{
	t_point	*p1;
	t_point	*p2;
	t_line	line;

	p1 = (t_point *) vec_get(map_line, i);
	p2 = (t_point *) vec_get(map_next, i);
	if (p1 && p2)
		draw_connection(*p1, *p2, line, ctx);
}

void	draw_hv_lines(t_vec *map_line, t_vec *map_next, int i, t_context *ctx)
{
	draw_horiz_line(map_line, i, ctx);
	draw_vert_line(map_line, map_next, i, ctx);
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
		if (map_next)
		{
			while (x < map_line->len - 1)
			{
				draw_hv_lines(map_line, map_next, x, ctx);
				if (x == map_line->len - 2)
					draw_vert_line(map_line, map_next, x + 1, ctx);
				if (y == ctx->map.len - 2)
					draw_horiz_line(map_next, x, ctx);
				x++;
			}
		}
		y++;
	}
}
