/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:00:29 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/17 23:38:33 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	colorslide(t_frame_buffer *fb, int win_w, int win_h)
{
	int	y;
	int	x;
	int	xc;
	int	yc;

	y = 0;
	while (y < win_h)
	{
		x = 0;
		while (x < win_w)
		{
			xc = (float)x / (float)win_w * 30 ;
			yc = (float)y / (float)win_h * 30 ;
			img_pixel_put(fb, x, y,
				rgb_to_int(xc + 10, yc + 10, 10 + (float)(xc + yc) / (float)2));
			x++;
		}
		y++;
	}
}

void	blank(t_frame_buffer *fb)
{
	ft_memset(fb->data, rgb_to_int(0, 0, 0), WIN_W * WIN_H * 4);
}
	/*
	int x;
	int y;

	y = 0;
	while (y < win_h)
	{
		x = 0;
		while (x < win_w)
		{
			img_pixel_put(fb, x, y, rgb_to_int(15, 20, 15));
			x++;
		}
		y++;
	} */
