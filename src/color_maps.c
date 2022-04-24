/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:43:54 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/24 23:35:04 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rainbow_color(t_point *color, t_point *p, t_context *ctx)
{
	if (p->c < 0)
	{
		color->x = 0;
		color->y = 125 - sin(((float)p->y + ctx->t.frame_n * 3) / 50.0) * 80 ;
		if (ctx->dims.z_min != 0)
			color->z = p->c / ctx->dims.z_min * 255;
		else
			color->z = 0;
	}
	else
	{
		if (ctx->dims.z_max != 0)
			color->x = (p->c - ctx->dims.z_min)
				/ (ctx->dims.z_max - ctx->dims.z_min) * 255;
		else
			color->x = 0;
		color->y = 125 - sin(((float)p->y + ctx->t.frame_n * 3) / 50.0) * 80 ;
		color->z = 255 - color->y ;
	}
}

void	red_blue(t_point *color, t_point *p, t_context *ctx)
{
	if (ctx->dims.z_max - ctx->dims.z_min == 0)
	{
		color->x = 222;
		color->y = 222;
		color->z = 222;
	}
	else
	{
		color->x = (p->c - ctx->dims.z_min) / (ctx->dims.z_max
				- ctx->dims.z_min) * 255;
		color->y = 155 - (p->c - ctx->dims.z_min) / (ctx->dims.z_max
				- ctx->dims.z_min) * 155;
		color->z = 255 - (p->c - ctx->dims.z_min) / (ctx->dims.z_max
				- ctx->dims.z_min) * 255;
	}
}

void	black_white(t_point *color, t_point *p, t_context *ctx)
{
	if (ctx->dims.z_max - ctx->dims.z_min == 0)
	{
		color->x = 222;
		color->y = 222;
		color->z = 222;
	}
	else
	{
		color->x = (p->c - ctx->dims.z_min) / (ctx->dims.z_max
				- ctx->dims.z_min) * 255;
		color->y = (p->c - ctx->dims.z_min) / (ctx->dims.z_max
				- ctx->dims.z_min) * 255;
		color->z = (p->c - ctx->dims.z_min) / (ctx->dims.z_max
				- ctx->dims.z_min) * 255;
	}
}

void	rainbow_z_color(t_point *color, t_point *p, t_context *ctx)
{
	double	stretch;

	stretch = (ctx->dims.z_max - ctx->dims.z_min) * 0.1;
	if (ctx->dims.z_max - ctx->dims.z_min == 0)
	{
		color->x = 222;
		color->y = 222;
		color->z = 222;
	}
	else
	{
		color->x = 160 - sin(((float)p->c + ctx->t.frame_n * 0.9 * stretch / 10)
				/ stretch) * 90 ;
		color->y = 160 + sin(((float)p->c + ctx->t.frame_n * 1.1 * stretch / 10)
				/ stretch) * 90 ;
		color->z = 160 + sin(((float)p->c + ctx->t.frame_n * 1.3 * stretch / 10)
				/ stretch) * 90 ;
	}
}
