/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:05:14 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/25 00:14:11 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_rotate(t_point *p, t_context *ctx)
{
	float	x;
	float	y;
	float	rotation;

	rotation = ctx->t.rot / 1000.0;
	p->x *= ctx->t.scale;
	p->y *= ctx->t.scale;
	p->z *= ctx->t.scale;
	p->z *= ctx->t.zscale;
	x = p->x;
	y = p->y;
	p->x = x * cos(rotation) - y * sin(rotation);
	p->y = y * cos(rotation) + x * sin(rotation);
}

/*
	scale map after transforms to fill the screen
 */
void	world_to_view(t_point *p, int x, int y)
{
	p->x = ((float)WIN_W / 2.0) + p->x * (WIN_W / INIT_SCALE);
	p->y = ((float)WIN_H / 2.0) + p->y * (WIN_W / INIT_SCALE);
	p->x += x;
	p->y += y;
	if (p->y > WIN_H + Z_LIMIT)
		p->y = WIN_H + Z_LIMIT;
	if (p->y < -Z_LIMIT)
		p->y = -Z_LIMIT;
}

/*
	normalize map coordinates from (0, map_max_dimension) to (-1, 1)
 */
void	model_to_world_per_point(t_point *p, t_context *ctx)
{
	float	big_dim;
	float	offset;

	if (ctx->dims.w > ctx->dims.h)
	{
		big_dim = ctx->dims.w;
		p->x = p->x / (big_dim - 1) * 2 - 1;
		offset = 1 - ctx->dims.h / big_dim;
		p->y = p->y / (big_dim - 1) * 2 - 1 + offset;
	}
	else
	{
		big_dim = ctx->dims.h;
		p->y = p->y / (big_dim - 1) * 2 - 1 ;
		offset = 1 - ctx->dims.w / big_dim;
		p->x = p->x / (big_dim - 1) * 2 - 1 + offset;
	}
	p->z = p->z / (big_dim - 1) * 2;
}

void	switch_auto_rotation(t_context *ctx)
{
	if (ctx->t.auto_rotate == 1)
		ctx->t.auto_rotate = 0;
	else if (ctx->t.auto_rotate == 0)
		ctx->t.auto_rotate = -1;
	else if (ctx->t.auto_rotate == -1)
		ctx->t.auto_rotate = 1;
}

void	do_transforms(t_point *p, t_context *ctx)
{
	scale_rotate(p, ctx);
	project(ctx, p);
	world_to_view(p, ctx->t.shift_x, ctx->t.shift_y);
}
