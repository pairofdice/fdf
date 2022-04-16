/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:05:14 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/16 13:38:39 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// 2d_x = (3d_x - 3d_z) * cos(30)
// 2d_z = -3d_y + (3d_x + 3d_z) * sin(30)
/*
	#include <stdio.h>
void	rotate(t_point *p, float rot)
{
	float x = p->x;
	float y = p->y;
	p->x = x * cos(rot) - y * sin(rot);
	p->y = y * cos(rot) + x * sin(rot);
	// printf("\n ??? %f", p->y);
}
 */
void	scale_rotate(t_point *p, t_context *ctx)
{
	float x;
	float y;
	float rotation;

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
void	scale(t_point *p, t_context *ctx)
{
/* 	p->x *= gen_multiplier;
	p->y *= gen_multiplier;
	p->z *= gen_multiplier; */
	p->z *= ctx->t.zscale;
}


void	translate(t_point *p, int x, int y)
{
	p->x += x;
	p->y += y;
}

void	world_to_view(t_point *p, int win_w, int win_h)
{

	p->x = ((float)win_w/2.0) + p->x * (win_w / 4.0 );
	p->y = ((float)win_h/2.0) + p->y * (win_h / 4.0 );
	p->z = p->z * 0.5;
}

/*
	normalize map coordinates from (0, something) to (-1, 1)
 */
void	model_to_world_per_point(t_point *p, t_context *ctx)
{
	float	big_dim;
	float	offset;

	if (ctx->dims.w > ctx->dims.h)
	{
		big_dim = ctx->dims.w;
		p->x = p->x / (big_dim - 1 ) * 2 - 1;
		offset = 1 -  ctx->dims.h /  big_dim;
		p->y = p->y / (big_dim - 1 ) * 2 - 1 + offset;
	}
	else
	{
		big_dim = ctx->dims.h;
		p->y = p->y / (big_dim - 1 ) * 2 - 1 ;
		offset = 1 -  ctx->dims.w /  big_dim;
		p->x = p->x / (big_dim - 1 ) * 2 - 1 + offset;
	}
/* 	ctx->dims.z_min /= big_dim;
	ctx->dims.z_max /= big_dim; */
	p->z = p->z / big_dim;
}

void	switch_auto_rotation(t_context *ctx)
{
	ft_putchar('H');
	if(ctx->t.auto_rotate == 1)
		ctx->t.auto_rotate = 0;
	else if(ctx->t.auto_rotate == 0)
		ctx->t.auto_rotate = -1;
	else if(ctx->t.auto_rotate == -1)
		ctx->t.auto_rotate = 1;
}
