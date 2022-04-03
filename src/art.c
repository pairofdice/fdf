/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   art.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:00:29 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/02 11:08:57 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void art_project(t_frame_buffer *fb, int win_w, int win_h)
{
	int y = 0;
	int xc;
	int yc;
	int xyc;
	while (y < win_h)
	{
		int x = 0;
		while (x < win_w)
		{
			xc = (float)x/(float)win_w * 255;
			yc = (float)y/(float)win_h * 255;
			xyc = (float)(x + y)/(float)4 ;
			img_pixel_put(fb, x, y, rgb_to_int(xc, yc, (float)(xc + yc) / (float)2));
			x++;
		}
		y++;
	}
}
