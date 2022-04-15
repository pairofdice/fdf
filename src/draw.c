/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:01:21 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/15 08:18:24 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_transforms(t_point *p, t_context *ctx)
{
	scale(p, ctx->t.scale, ctx->t.zscale);
	rotate(p, ctx->t.rot / 1000.0);
	project(ctx, p);

	world_to_view(p, ctx->w, ctx->h);
	translate(p, ctx->t.shift_x, ctx->t.shift_y);
}

int	points_in_window(t_line *l, t_context *ctx)
{
	if (l->a.x < 0 || l->a.y < 0 || l->a.x >= ctx->w || l->a.y >= ctx->h)
		return (0);
	if (l->b.x < 0 || l->b.y < 0 || l->b.x >= ctx->w || l->b.y >= ctx->h)
		return (0);

	return (1);
}

int	draw_frame(t_context *ctx)
{
	ctx->t.frame_n++;
	ctx->t.rot += ctx->t.auto_rotate * 5;
	if (ctx->draw_bg)
		colorslide(&ctx->fb, ctx->w, ctx->h);
	else
		blank(&ctx->fb, ctx->w, ctx->h);
	if (ctx->map.len > 0)
		draw_map(ctx);
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->fb.img, 0, 0);
	help_text(ctx);
	return (1);
}
//ft_memcpy(ctx->fb.data, ctx->fb.databg,
//		ctx->fb.bits_per_pixel * ctx->w * ctx->h / 8);
