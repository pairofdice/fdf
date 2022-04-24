/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:01:21 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/24 23:38:04 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_frame(t_context *ctx)
{
	ctx->t.frame_n++;
	ctx->t.rot += ctx->t.auto_rotate * ctx->t.auto_rotate_rate;
	if (ctx->draw_bg == 1)
		copy_bg(&ctx->fb);
	else
		blank(&ctx->fb);
	if (ctx->map.len > 0)
		draw_map(ctx);
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->fb.img, 0, 0);
	help_text(ctx);
	return (1);
}
