/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:15:47 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/22 14:38:55 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_context(t_context *ctx)
{
	ctx->mlx = mlx_init();
	ctx->fb.img = mlx_new_image(ctx->mlx, WIN_W, WIN_H);
	ctx->fb.imgbg = mlx_new_image(ctx->mlx, WIN_W, WIN_H);
	ctx->fb.data = mlx_get_data_addr(ctx->fb.img, &ctx->fb.bits_per_pixel,
			&ctx->fb.line_length, &ctx->fb.endian);
	ctx->fb.databg = mlx_get_data_addr(ctx->fb.imgbg, &ctx->fb.bits_per_pixel,
			&ctx->fb.line_length, &ctx->fb.endian);
	ctx->win = mlx_new_window(ctx->mlx, WIN_W, WIN_H, "Machine State");
	ctx->t.rot = 0;
	ctx->t.shift_x = 0;
	ctx->t.shift_y = 0;
	ctx->t.scale = 1;
	ctx->t.zscale = 1;
	ctx->t.auto_rotate = 0;
	ctx->w = WIN_W;
	ctx->h = WIN_H;
	ctx->draw_bg = 1;
	ctx->dims.z_min = Z_LIMIT;
	ctx->dims.z_max = -Z_LIMIT;
	ctx->t.projection = NUM_PROJ;
	ctx->t.perspective = 1;
}

void	reset(t_context *ctx)
{
	ctx->t.rot = 0;
	ctx->t.shift_x = 0;
	ctx->t.shift_y = 0;
	ctx->t.scale = 1;
	ctx->t.zscale = 1;
	ctx->t.auto_rotate = 0;
	ctx->draw_bg = 1;
	ctx->t.projection = NUM_PROJ;
	ctx->t.perspective = -1;
}

void	set_z_range(t_context *ctx, double i)
{
	if (i < ctx->dims.z_min)
		ctx->dims.z_min = i;
	if (i > ctx->dims.z_max)
		ctx->dims.z_max = i;
}

void	max_dimensions(t_context *ctx)
{
	unsigned long	i;
	unsigned long	j;
	t_point			*p;
	t_vec			line;

	i = 0;
	ctx->dims.h = ctx->map.len;
	ctx->dims.w = 0;
	while (i < ctx->map.len)
	{
		line = *(t_vec *)vec_get(&ctx->map, i);
		if (ctx->dims.w < line.len)
			ctx->dims.w = line.len;
		j = 0;
		while (j < line.len)
		{
			p = (t_point *)vec_get(&line, j);
			set_z_range(ctx, p->z);
			model_to_world_per_point(p, ctx);
			j++;
		}
		i++;
	}
}
