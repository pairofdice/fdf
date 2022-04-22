/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:20:23 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/22 14:38:23 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	checked_pixel_put(t_frame_buffer *fb, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
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
