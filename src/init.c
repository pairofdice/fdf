/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:15:47 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/12 11:09:08 by jsaarine         ###   ########.fr       */
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
	ctx->t.auto_rotate = 1;

	ctx->w = WIN_W;
	ctx->h = WIN_H;
	ctx->draw_bg = 0;
	//max_dimss(ctx);

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

/*
void	check_line_z(t_vec *line, t_dims *dims)
{
	int		j;
	t_point	p;

 	dims->z_min = 2147483647;
	dims->z_max = -2147483648;
	j = 0;
	while (j < line->len)
	{
		p = *(t_point *)vec_get(line, j);
		if (dims->z_max < p.z)
			dims->z_max = p.z;
		if (dims->x_max < p.z)
			dims->x_max = p.z;
		j++;
	}
}

void	max_dimss(t_context *ctx)
{
	int		i;
	t_vec	line;

	i = 0;
	dims->y_max = map->len;
	dims->x_max = 0;
	while (i < map->len)
	{
		line = *(t_vec *)vec_get(ctx->map, i);
		 if (dims->x_max <  line.len)
		 	dims->x_max = line.len;
		check_line_z(&line, dims);
		i++;
	}
} */
/*
2147483647
-2147483648
 */
