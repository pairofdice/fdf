/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:14:02 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/12 12:03:36 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../minilibx/mlx.h" */
#include "fdf.h"
#include <stdlib.h>

#include <unistd.h>

//# include "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks/Carbon.framework/Versions/A/Frameworks/HIToolbox.framework/Versions/A/Headers/Events.h"

// ILLEGAL!!!!
#include <stdio.h>
#include <math.h>

int clamp(int nb, int boundary)
{
	if (nb > boundary)
		nb = boundary;
	return (nb);
}


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

/* int fdf_close(int keycode, t_context *ctx)
{
	mlx_destroy_window(ctx->mlx, ctx->win);
	return (0);
} */


void	hook_em_up(t_context *ctx)
{
	mlx_loop_hook(ctx->mlx, draw_frame, ctx);
	//mlx_key_hook(ctx->win, on_keypress, ctx);
	 mlx_hook(ctx->win, ON_KEYDOWN, 0, on_keypress, ctx);
	//mlx_hook(ctx->win, ON_KEYDOWN, (1L<<0), on_keypress, ctx);
	mlx_hook(ctx->win, 33, 0, fdf_close, ctx); // 33 on macbook air, 17 on school?
}
	//mlx_hook(ctx->win, ON_DESTROY, 0L, fdf_close, ctx);
	//mlx_hook(ctx->win, ON_MOUSEMOVE, 0, on_mouse_move, ctx);
/*
	mlx_hook(ctx->win, ON_MOUSEDOWN, 0, on_mouse_down, ctx);
	mlx_hook(ctx->win, ON_MOUSEUP, 0, on_mouse_up, ctx); */

	// usage
	// mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);

int	main(int argc, char **argv)
{
	t_context	ctx;

	handle_args(argc, argv, &ctx.map);
	max_dims(&ctx.map, &ctx.max);
	init_context(&ctx);
	background(&ctx.fb, ctx.w, ctx.h);
	hook_em_up(&ctx);
	mlx_loop(ctx.mlx);


	return (0);
}

/*
#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
*/
