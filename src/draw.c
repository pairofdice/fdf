/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:01:21 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/22 18:03:19 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
