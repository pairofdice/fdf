/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_it.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:59:05 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/21 16:09:33 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_keypress(int key_nb, t_context *ctx)
{
	on_keys_a(key_nb, ctx);
	on_keys_b(key_nb, ctx);
	return (0);
}

int	fdf_close(t_context *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	on_mouse_down(int button, int x, int y, t_context *ctx)
{
	printf("%d %d %d\n", button, x, y);
	if (x >= 0 && x < WIN_W && y - 31868>= 0 && y - 31868 < WIN_H)
	{
		if (button == 2)
			ctx->right_mouse_dn = 1;
		if (button == 1)
			ctx->left_mouse_dn = 1;
	}
	return (0);
}

int	on_mouse_move(int x, int y, t_context *ctx)
{
	int	dx;
	int	dy;

	dx = ctx->mouse_x - x;
	dy = ctx->mouse_y + 31868 - y;
	if (ctx->right_mouse_dn == 1)
	{
		ctx->t.shift_x -= dx;
		ctx->t.shift_y -= dy;
	}
	if (ctx->left_mouse_dn == 1)
	{
		ctx->t.zscale += dy / 333.0;
	}
	ctx->mouse_x = x;
	ctx->mouse_y = y - 31868;
	return (0);
}

int	on_mouse_up(int button, int x, int y, t_context *ctx)
{
	if (x || y)
	{
	}
	if (button == 2)
		ctx->right_mouse_dn = 0;
	if (button == 1)
		ctx->left_mouse_dn = 0;
	return (0);
}
/*

int fdf(void *param)

ON_KEYDOWN 	2 	int (*f)(int keycode, void *param)
ON_KEYUP* 	3 	int (*f)(int keycode, void *param)
ON_MOUSEDOWN* 	4 	int (*f)(int button, int x, int y, void *param)
ON_MOUSEUP 	5 	int (*f)(int button, int x, int y, void *param)
ON_MOUSEMOVE 	6 	int (*f)(int x, int y, void *param)
ON_EXPOSE* 	12 	int (*f)(void *param)
ON_DESTROY 	17 	int (*f)(void *param) */
