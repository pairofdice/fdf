/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:14:02 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/13 12:22:07 by jsaarine         ###   ########.fr       */
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
	// usage
	// mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);

int	main(int argc, char **argv)
{
	t_context	ctx;

	handle_args(argc, argv, &ctx.map);
	max_dims(&ctx.map, &ctx.max);
	init_context(&ctx);
	// background(&ctx.fb, ctx.w, ctx.h);
	hook_em_up(&ctx);
	mlx_loop(ctx.mlx);
	return (0);
}
