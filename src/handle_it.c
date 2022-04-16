/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_it.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:59:05 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/16 13:52:15 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	on_keypress(int key_nb, t_context *ctx)
{
	ft_putnbr(key_nb);
	ft_putchar('\n');
	if (key_nb == KEYMB_ESC || key_nb == 53)
		fdf_close(ctx);
	if (key_nb == KEYMB_Q || key_nb == 12)
		ctx->t.rot -= 128.0;
	if (key_nb == KEYMB_E || key_nb == 14)
		ctx->t.rot += 128.0;
	if (key_nb == KEYMB_R || key_nb == 15)
		ctx->t.scale *= 1.1;
	if (key_nb == KEYMB_F || key_nb == 3)
		ctx->t.scale *= 0.9;
 	if (key_nb == KEYMB_T || key_nb == 17)
		ctx->t.zscale += 0.05;
	if (key_nb == KEYMB_G || key_nb == 5)
		ctx->t.zscale -= 0.05;
	if (key_nb == KEYMB_D || key_nb == 2)
		ctx->t.shift_x += 10;
	if (key_nb == KEYMB_A || key_nb == 0)
		ctx->t.shift_x -= 10;
	if (key_nb == KEYMB_S || key_nb == 1)
		ctx->t.shift_y += 10;
	if (key_nb == KEYMB_W || key_nb == 13)
		ctx->t.shift_y -= 10;
	if (key_nb == KEYMB_B || key_nb == 11)
		switch_auto_rotation(ctx);
	if (key_nb == KEYMB_P || key_nb == 35)
	{
		ctx->t.projection++;
		ctx->t.projection %= NUM_PROJ + 1;
	}
	if (key_nb == KEYMB_Z || key_nb == 6)
		reset(ctx);
	return (1);
}

int	fdf_close(t_context *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	on_mouse_down(int button, int x, int y, t_context *ctx)
{
	if (button == 2)
		ctx->right_mouse_dn = 1;
/* 	ft_putchar('M');
	ft_putnbr(button); */
	return(0);
}

int	on_mouse_move(int x, int y, t_context *ctx)
{
	int dx;
	int dy;

	dx = ctx->mouse_x - x;
	dy = ctx->mouse_y + 31868 - y;
	if (ctx->right_mouse_dn == 1)
	{
	 	ctx->t.shift_x -= dx;
		ctx->t.shift_y -= dy;
	}
	ctx->mouse_x = x;
	ctx->mouse_y = y - 31868;
	return(0);
}

int	on_mouse_up(int button, int x, int y, t_context *ctx)
{
	if (button == 2)
		ctx->right_mouse_dn = 0;
	return(0);
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
