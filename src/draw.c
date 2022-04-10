/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:01:21 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/10 23:04:19 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	do_transforms(t_point *p, t_context *ctx)
{
	model_to_world(p, &ctx->max);
	scale(p, ctx->t.scale);
	zscale(p, ctx->t.zscale);
	rotate(p, ctx->t.frame_n / 1000.0);
	isometric(p);
	world_to_view(p, ctx->w, ctx->h);
	translate(p, ctx->t.shift_x, ctx->t.shift_y);
}

void	draw_map(t_context *ctx)
{
	int		x;
	int		y;
	t_vec	*map_line;
	t_vec	*map_next;
	t_line	line;

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
				t_point p1 = *(t_point *) vec_get(map_line, x);
				t_point p2 = *(t_point *) vec_get(map_line, x + 1);
				t_point p3 = *(t_point *) vec_get(map_next, x);

				do_transforms(&p1, ctx);
				line.a = p1;
				do_transforms(&p2, ctx);
				line.b = p2;
				draw_line(&line, ctx);
				do_transforms(&p3, ctx);
				line.b = p3;
				draw_line(&line, ctx);
				if (x == map_line->len - 2)
				{
					p3 = *(t_point *) vec_get(map_next, x + 1);
					do_transforms(&p3, ctx);
					line.a = p2;
					line.b = p3;
					draw_line(&line, ctx);
				}
				if (y == ctx->map.len - 2)
				{
					p2 = *(t_point *) vec_get(map_next, x + 1);
					p3 = *(t_point *) vec_get(map_next, x);
					do_transforms(&p2, ctx);
					do_transforms(&p3, ctx);
					line.a = p3;
					line.b = p2;
					draw_line(&line, ctx);
				}
				x++;
			}
		}
		y++;
	}
}

int		points_in_win(t_line *l, int win_w, int win_h)
{
	if (l->a.x < 0 || l->a.y < 0 || l->a.x >= win_w || l->a.y >= win_h)
		return (0);
	if (l->b.x < 0 || l->b.y < 0 || l->b.x >= win_w || l->b.y >= win_h)
		return (0);
	return (1);
}

int	draw_frame(void *context)
{
	t_context *ctx;

	ctx = (t_context *)context;
	ctx->t.frame_n++;
	ctx->t.frame_n++;
	background(&ctx->fb, ctx->w, ctx->h);
	ft_memcpy(ctx->fb.data, ctx->fb.databg, ctx->fb.bits_per_pixel * ctx->w * ctx->h / 8);
	draw_map(context);
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->fb.img, 0, 0);
	help_text(context);
	return (1);
}


