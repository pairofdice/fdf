/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:14:02 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/18 17:31:18 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

		//line_vec = (t_vec *)map->memory[r].memory;
		// ptr = &map->memory[r];
		//line_vec = (t_vec *) &map->memory[r];
void	print_map(t_vec *map)
{
	t_vec	*line_vec;
	size_t	r;
	size_t	k;
	t_point	p;

	r = 0;
	while (r < map->len)
	{
		line_vec = vec_get(map, r++);
		k = 0;
		while (k < line_vec->len)
		{
			p = *(t_point *)vec_get(line_vec, k++);
			//printf("[%4.1f %4.1f]", p.z, p.c);
		}
		printf("\n");
	}
}

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
	max_dimensions(&ctx);
	color_range_map(&ctx);
	print_map(&ctx.map);
	hook_em_up(&ctx);
	mlx_loop(ctx.mlx);
	return (0);
}
