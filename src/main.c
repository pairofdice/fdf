/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:14:02 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/10 23:45:51 by jsaarine         ###   ########.fr       */
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

void blank(t_frame_buffer *fb, int win_w, int win_h)
{
	int y = 0;

	while (y < win_h)
	{
		int x = 0;
		while (x < win_w)
		{

			img_pixel_put(fb, x, y, rgb_to_int(0, 0, 0));
			x++;
		}
		y++;
	}
}

void	max_dims(t_vec *map, t_point *max)
{
	int i;
	t_vec line;

	i = 0;
	max->y = map->len;
	max->x = 0;
	while (i < map->len)
	{
		line = *(t_vec *)vec_get(map, i);

		 if ( max->x <  line.len)
		 	max->x = line.len;
		i++;
	}
}

	//ft_putnbr(key_nb);
	//ft_putchar('\n');
int fdf_close(int keycode, t_context *ctx)
{
	mlx_destroy_window(ctx->mlx, ctx->win);
	exit (0);
	return (0);
}

int on_keypress(int key_nb, void *param)
{
	t_context *ctx;

	ctx = (t_context *) param;
 	if (key_nb == 53 || key_nb == 65307)
	{
		mlx_destroy_window(ctx->mlx, ctx->win);
		exit (0);
	}
	if (key_nb == 113)
		ctx->t.rot -= M_PI / 32.0;
	if (key_nb == 101)
		ctx->t.rot += M_PI / 32.0;
	if (key_nb == 114)
		ctx->t.scale *= 1.1;
	if (key_nb == 102)
		ctx->t.scale *= 0.9;
	if (key_nb == 116)
		ctx->t.zscale +=  0.2;
	if (key_nb == 103)
		ctx->t.zscale -=  0.2;
	if (key_nb == 100)
		ctx->t.shift_x +=  10;
	if (key_nb == 97)
		ctx->t.shift_x -=  10;
	if (key_nb == 115)
		ctx->t.shift_y +=  10;
	if (key_nb == 119)
		ctx->t.shift_y -=  10;
	return (1);
}

int		on_mousepress(int button,int x,int y,void *param)
{
	ft_putnbr(button);
	ft_putchar('\n');
	rotate(param, 0.1);
	/* if (key_nb == 53 || key_nb == 65307)
		exit (1); */

	return (1);
}

void print_map(t_vec * map)
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

void hook_em_up(t_context *ctx)
{
	//mlx_key_hook(ctx->win, on_keypress, ctx);
	mlx_loop_hook(ctx->mlx, draw_frame, ctx);
	mlx_hook(ctx->win, ON_DESTROY, 1L<<0, fdf_close, ctx);
	//mlx_hook(ctx->win, ON_KEYDOWN, 1L<<0, on_keypress, ctx);
}

int main(int argc, char **argv)
{
	t_context ctx;

	handle_args(argc, argv, &ctx.map);
	max_dims(&ctx.map, &ctx.max);
	init_context(&ctx);
	background(&ctx.fb, ctx.w, ctx.h);
	hook_em_up(&ctx);
	mlx_loop(ctx.mlx);
	return (0);
}
