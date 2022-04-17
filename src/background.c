/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:00:29 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/18 00:09:10 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	save_colorslide(t_frame_buffer *fb)
{
	int	y;
	int	x;
	int	xc;
	int	yc;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			xc = (float)x / (float)WIN_W * 30 ;
			yc = (float)y / (float)WIN_H * 30 ;
			save_bg(fb, x, y,
				rgb_to_int(xc + 10, yc + 10, 10 + (float)(xc + yc) / (float)2));
			x++;
		}
		y++;
	}
}

void	copy_bg(t_frame_buffer *fb)
{
	ft_memcpy(fb->data, fb->databg, WIN_W * WIN_H * 4);
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
