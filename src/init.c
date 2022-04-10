/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:15:47 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/10 22:53:02 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// , t_vec *map, int fd
void	init_context(t_context *ctx)
{

	ctx->mlx = mlx_init();
	ctx->fb.img = mlx_new_image(ctx->mlx, WIN_W, WIN_H);
	ctx->fb.data = mlx_get_data_addr(ctx->fb.img, &ctx->fb.bits_per_pixel, &ctx->fb.line_length, &ctx->fb.endian);
	ctx->fb.databg = mlx_get_data_addr(ctx->fb.img, &ctx->fb.bits_per_pixel, &ctx->fb.line_length, &ctx->fb.endian);
	ctx->win = mlx_new_window(ctx->mlx, WIN_W, WIN_H, "Machine State");
	ctx->t.rot = 0;
	ctx->t.shift_x = 0;
	ctx->t.shift_y = 0;
	ctx->t.scale = 1;
	ctx->t.zscale = 1;
	ctx->w = WIN_W;
	ctx->h = WIN_H;
}
