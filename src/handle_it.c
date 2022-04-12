/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_it.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:59:05 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/12 16:17:39 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int	on_keypress(int key_nb, t_context *ctx)
{
	ft_putnbr(key_nb);
	ft_putchar('\n');
 	if (key_nb == 53 || key_nb == 65307)
		fdf_close(ctx);
	if (key_nb == 113 || key_nb == 12)
		ctx->t.rot -= 128.0;
	if (key_nb == 101 || key_nb == 14)
		ctx->t.rot += 128.0;
	if (key_nb == 114 || key_nb == 15)
		ctx->t.scale *= 1.1;
	if (key_nb == 102 || key_nb == 3)
		ctx->t.scale *= 0.9;
	if (key_nb == 116 || key_nb == 17)
		ctx->t.zscale +=  0.2;
	if (key_nb == 103 || key_nb == 5)
		ctx->t.zscale -=  0.2;
	if (key_nb == 100 || key_nb == 2)
		ctx->t.shift_x +=  10;
	if (key_nb == 97 || key_nb == 0)
		ctx->t.shift_x -=  10;
	if (key_nb == 115 || key_nb == 1)
		ctx->t.shift_y +=  10;
	if (key_nb == 119 || key_nb == 13)
		ctx->t.shift_y -=  10;
	if (key_nb == 98 || key_nb == 11)
		switch_auto_rotation(ctx);
/* 	if (key_nb == 98 || key_nb == 11)
		switch_projection(ctx); */
	return (1);
}


int	fdf_close(t_context *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return(0);
}

/*
 int	on_mouse_down(int button, int x, int y, void *param)
{
	ft_putchar('M');
	return(0);
}

int	on_mouse_up(int button, int x, int y, void *param)
{

}

int	on_mouse_move(int x, int y, void *param)
{

}

int fdf(void *param)

ON_KEYDOWN 	2 	int (*f)(int keycode, void *param)
ON_KEYUP* 	3 	int (*f)(int keycode, void *param)
ON_MOUSEDOWN* 	4 	int (*f)(int button, int x, int y, void *param)
ON_MOUSEUP 	5 	int (*f)(int button, int x, int y, void *param)
ON_MOUSEMOVE 	6 	int (*f)(int x, int y, void *param)
ON_EXPOSE* 	12 	int (*f)(void *param)
ON_DESTROY 	17 	int (*f)(void *param) */
