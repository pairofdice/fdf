/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:20:23 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/18 00:01:41 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	checked_pixel_put(t_frame_buffer *fb, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 900 && y >= 0 && y < 900)
	{
		dst = fb->data + (y * fb->line_length + x * (fb->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	save_bg(t_frame_buffer *fb, int x, int y, int color)
{
	char	*dst;

	dst = fb->databg + (y * fb->line_length + x * (fb->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	img_pixel_put(t_frame_buffer *fb, int x, int y, int color)
{
	char	*dst;

	dst = fb->data + (y * fb->line_length + x * (fb->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	rgb_to_int(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

