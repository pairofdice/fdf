/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   art.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:00:29 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/10 11:58:04 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	art_project(t_frame_buffer *fb, int win_w, int win_h)
{
	int	y;
	int	x;
	int	xc;
	int	yc;
	int	xyc;

	y = 0;
	while (y < win_h)
	{
		x = 0;
		while (x < win_w)
		{
			xc = (float)x / (float)win_w * 30 ;
			yc = (float)y / (float)win_h * 30 ;
			xyc = (float)(x + y) / (float)2 ;
			img_pixel_put(fb, x, y,
				rgb_to_int(xc + 10, yc + 10, 10 + (float)(xc + yc) / (float)2));
			x++;
		}
		y++;
	}
}
