/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:15:47 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/16 13:58:10 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// , t_vec *map, int fd
void	init_context(t_context *ctx)
{
	ctx->mlx = mlx_init();
	ctx->fb.img = mlx_new_image(ctx->mlx, WIN_W, WIN_H);
	ctx->fb.data = mlx_get_data_addr(ctx->fb.img, &ctx->fb.bits_per_pixel, &ctx->fb.line_length, &ctx->fb.endian);
	ctx->fb.databg = mlx_get_data_addr(ctx->fb.img, &ctx->fb.bits_per_pixel, &ctx->fb.line_length, &ctx->fb.endian);
	ctx->win = mlx_new_window(ctx->mlx, WIN_W, WIN_H, "Machine State");
	ctx->t.rot = 0;
	ctx->t.shift_x = 0;
	ctx->t.shift_y = 0;
	ctx->t.scale = 1;
	ctx->t.zscale = 1;
	ctx->t.auto_rotate = 0;
	ctx->w = WIN_W;
	ctx->h = WIN_H;
	ctx->draw_bg = 0;
	ctx->dims.z_min = 1024.0;
	ctx->dims.z_max = -1024.0;
	ctx->t.projection = NUM_PROJ;
	ctx->t.perspective = 1;
}

void	reset(t_context *ctx)
{
	ctx->t.rot = 0;
	ctx->t.shift_x = 0;
	ctx->t.shift_y = 0;
	ctx->t.scale = 1;
	ctx->t.zscale = 1;
	ctx->t.auto_rotate = 0;
	ctx->draw_bg = 1;
	ctx->t.projection = NUM_PROJ;
	ctx->t.perspective = -1;
}

/*
void	model_to_world(t_context *ctx)
{
	int		i;
	int		j;
	t_point *p;
	t_vec	line;

	i = 0;
	while (i < ctx->map.len)
	{
		line = *(t_vec *)vec_get(&ctx->map, i);
		j = 0;
		while (j < line.len)
		{
			p = (t_point *)vec_get(&line, j);
			model_to_world_per_point(p, ctx);
			j++;
		}
		i++;
	}
} */

void	set_z_range(t_context *ctx, double i)
{
	if(i < ctx->dims.z_min)
	{
	//ft_putnbr(ctx->dims.z_min);
		ctx->dims.z_min = i;
		if (ctx->dims.z_min < -1024)
			ctx->dims.z_min = -1024;
	}
	//ft_putchar('_');
	if(i > ctx->dims.z_max)
	{
	//ft_putnbr(ctx->dims.z_max);
		ctx->dims.z_max = i;
		if (ctx->dims.z_min > 1024)
			ctx->dims.z_min = 1024;
	}
	//ft_putchar(',');
	//ft_putchar(' ');
}

void color_spread(t_context *ctx, t_point *p)
{
	//printf(" %4.2f, ", p->c);
	p->c -= ctx->dims.z_min;/*
	if (ctx->dims.z_max != 0) */
	p->c /= ctx->dims.z_max ;
	//p->c -= 1;
	//printf("%4.2f |", p->c);
}

void	color_range_map(t_context *ctx)
{
	int		i;
	int		j;
	t_point *p;
	t_vec	line;

	i = 0;
	while (i < ctx->map.len)
	{
		line = *(t_vec *)vec_get(&ctx->map, i);
		j = 0;
		while (j < line.len)
		{
			p = (t_point *)vec_get(&line, j);
			color_spread(ctx, p);
			j++;
		}
		i++;
	}
}

void	max_dimensions(t_context *ctx)
{
	int		i;
	int		j;
	t_point *p;
	t_vec	line;

	i = 0;
	ctx->dims.h = ctx->map.len;
	ctx->dims.w = 0;
	while (i < ctx->map.len)
	{
		line = *(t_vec *)vec_get(&ctx->map, i);
		if (ctx->dims.w <  line.len)
		 	ctx->dims.w = line.len;
		j = 0;
		while (j < line.len)
		{
			p = (t_point *)vec_get(&line, j);
			set_z_range(ctx, p->z);
			model_to_world_per_point(p, ctx);
			j++;
		}
		i++;
	}
}
