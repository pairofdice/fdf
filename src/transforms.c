/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:05:14 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/12 16:17:57 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// 2d_x = (3d_x - 3d_z) * cos(30)
// 2d_z = -3d_y + (3d_x + 3d_z) * sin(30)

	#include <stdio.h>
void	rotate(t_point *p, float rot)
{
	float x = p->x;
	float y = p->y;
	p->x = x * cos(rot) - y * sin(rot);
	p->y = y * cos(rot) + x * sin(rot);
	// printf("\n ??? %f", p->y);
}

void	scale(t_point *p, float multiplier)
{
	p->x *= multiplier;
	p->y *= multiplier;
	p->z *= multiplier;
}


void	translate(t_point *p, int x, int y)
{
	p->x += x;
	p->y += y;
}


void	zscale(t_point *p, float multiplier)
{
	p->z *= multiplier;
}

void	world_to_view(t_point *p, int win_w, int win_h)
{

	p->x = ((float)win_w/2.0) + p->x * (win_w / 4.0 );
	p->y = ((float)win_h/2.0) + p->y * (win_h / 4.0 );

	//printf("%f \n", p->y);
/* 	p->x = p->x * 200.0;
	p->y = p->y * 200.0; */
	p->z = p->z * 0.5;
}

/*
	normalize map coordinates from (0, something) to (-1, 1)
 */

void	model_to_world(t_point *p, t_point *max)
{
	p->x = p->x / (max->x - 1 ) * 2 - 1;
	p->y = p->y / (max->y - 1 ) * 2 - 1;
	//printf("%f %f %f \n", p->y, max->x, max->y);
	// ft_max(max->x, max->y)
	p->z = p->z / 155.0;
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
