/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:01:21 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/18 00:11:05 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_transforms(t_point *p, t_context *ctx)
{
	scale_rotate(p, ctx);
	project(ctx, p);
	world_to_view(p, ctx->t.shift_x, ctx->t.shift_y);
}

int	neither_point_in_window(t_line *l, t_context *ctx)
{
	if (l->a.x < 0 || l->a.y < 0 || l->a.x >= ctx->w || l->a.y >= ctx->h)
	{
		if (l->b.x < 0 || l->b.y < 0 || l->b.x >= ctx->w || l->b.y >= ctx->h)
			return (1);
	}
	return (0);
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
		copy_bg(&ctx->fb);
	else
		blank(&ctx->fb);
	if (ctx->map.len > 0)
		draw_map(ctx);
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->fb.img, 0, 0);
	help_text(ctx);
	return (1);
}
		/* if (ctx->t.frame_n % 100 == 0)
			colorslide(&ctx->fb, ctx->w, ctx->h); */
//ft_memcpy(ctx->fb.data, ctx->fb.databg,
//		ctx->fb.bits_per_pixel * ctx->w * ctx->h / 8);
