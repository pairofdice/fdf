/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:26:45 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/22 18:13:23 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(t_point *color, t_point p, t_context *ctx)
{
	if (p.c < 0)
	{
		color->x = 0;
		color->y = 125 - sin(((float)p.y + ctx->t.frame_n) / 50.0) * 50 ;
		if (ctx->dims.z_min != 0)
			color->z = p.c / ctx->dims.z_min * 255;
		else
			color->z = 0;
	}
	else
	{
		if (ctx->dims.z_max != 0)
			color->x = p.c / ctx->dims.z_max * 255;
		else
			color->x = 0;
		color->y = 125 - sin(((float)p.y + ctx->t.frame_n) / 50.0) * 50 ;
		color->z = 255 - color->y ;
	}
}

int	rgb_to_int(t_point c)
{
	return ((int)c.x << 16 | (int)c.y << 8 | (int)c.z);
}
