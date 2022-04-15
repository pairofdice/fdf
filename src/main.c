/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:14:02 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/15 12:48:16 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../minilibx/mlx.h" */
#include "fdf.h"
#include <stdlib.h>
#include <unistd.h>

// ILLEGAL!!!!
#include <stdio.h>
#include <math.h>

void	print_map(t_vec * map)
{
	t_vec	*line_vec;
	size_t	r;
	r = 0;
	size_t k;
	t_point p;
	 while (r < map->len)
	{
		line_vec = vec_get(map, r++);
		//line_vec = (t_vec *)map->memory[r].memory;
		// ptr = &map->memory[r];
		//line_vec = (t_vec *) &map->memory[r];
		k = 0;
		while (k < line_vec->len)
		{
			p = *(t_point *)vec_get(line_vec, k++);
			printf("[%4.1f %4.1f %4.1f]", p.x, p.y, p.z);
		}
		printf("\n");
	}
}

void	hook_em_up(t_context *ctx)
{
	mlx_loop_hook(ctx->mlx, draw_frame, ctx);
	mlx_hook(ctx->win, ON_KEYDOWN, 1L<<0, on_keypress, ctx);
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
	max_dims(&ctx);
	color_range_map(&ctx);
	printf("\nmin max:%f %f\n", ctx.dims.z_min, ctx.dims.z_max);
	// printf("\nlerp 42, 69, 3, 10: %f \n", interpolate(42, 69, 3, 10));
	//model_to_world(&ctx);
	hook_em_up(&ctx);
	mlx_loop(ctx.mlx);
	return (0);
}
