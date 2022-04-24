/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:14:02 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/24 18:50:18 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook_em_up(t_context *ctx)
{
	mlx_loop_hook(ctx->mlx, draw_frame, ctx);
	mlx_hook(ctx->win, ON_KEYDOWN, 1L << 0, on_keypress, ctx);
	mlx_hook(ctx->win, ON_DESTROY, 0, fdf_close, ctx);
	mlx_hook(ctx->win, ON_MOUSEMOVE, 0, on_mouse_move, ctx);
	mlx_hook(ctx->win, ON_MOUSEDOWN, 0, on_mouse_down, ctx);
	mlx_hook(ctx->win, ON_MOUSEUP, 0, on_mouse_up, ctx);
}

int	main(int argc, char **argv)
{
	t_context	ctx;

	handle_args(argc, argv, &ctx);
	init_context(&ctx);
	colorslide(&ctx.fb);
	max_dimensions(&ctx);
	hook_em_up(&ctx);
	mlx_loop(ctx.mlx);
	return (0);
}
