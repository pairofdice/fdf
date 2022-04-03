/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:01:21 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/03 12:31:48 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pixel_put(t_frame_buffer *fb, int x, int y, int color)
{
	char	*dst;

	dst = fb->data + (y * fb->line_length + x * (fb->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int rgb_to_int(unsigned char r, unsigned char g, unsigned char b)
{
	int color;

	color = b;
	color = color | (int)g << 8;
	color = color | (int)r << 16;
	return (color);
}

void	draw_map(t_frame_buffer* fb, t_vec *map, int win_w, int win_h, t_point *max)
{
	size_t map_h;
	size_t map_w;
	float x_step;
	float y_step;
	float margin;
	int x;
	int y;
	t_vec	*map_line;
	t_vec	*map_next;
	t_line 	line;

	y = 0;
	while (y < map->len - 1)
	{
		map_line = (t_vec *)vec_get(map, y);
		map_next = (t_vec *)vec_get(map, y + 1);
		x = 0;
			while (x < map_line->len - 1)
			{
				t_point *p1 = (t_point *) vec_get(map_line, x);
				t_point *p2 = (t_point *) vec_get(map_line, x + 1);
				t_point *p3 = (t_point *) vec_get(map_next, x);

				line.a = *p1;
				line.b = *p2;
				draw_line(&line, fb, win_w, win_h);
				line.b = *p3;
				draw_line(&line, fb, win_w, win_h);


				if (x == map_line->len - 2)
				{
					p3 = (t_point *) vec_get(map_next, x + 1);
					line.a = *p2;
					line.b = *p3;
					draw_line(&line, fb, win_w, win_h);

				}
				if (y == map->len - 2)
				{
					p2 = (t_point *) vec_get(map_next, x + 1);
					p3 = (t_point *) vec_get(map_next, x);
					line.a = *p3;
					line.b = *p2;
					draw_line(&line, fb, win_w, win_h);

				}

				x++;
			}
		y++;
	}
}
int		points_in_win(t_line *l, int win_w, int win_h)
{
	if (l->a.x < 0 || l->a.y < 0 || l->a.x >= win_w || l->a.y >= win_h)
		return (0);
	if (l->b.x < 0 || l->b.y < 0 || l->b.x >= win_w || l->b.y >= win_h)
		return (0);
	return (1);
}


void	draw_line(t_line *line, t_frame_buffer *fb, int win_w, int win_h)
{
	float	dx;
	float	dy;
	float	dc;
	float	steps;
	unsigned char color;
	int		i;



	dc = (line->b.c - line->a.c);
	dx = (line->b.x - line->a.x);
	dy = (line->b.y - line->a.y);
	if (ft_abs(dx) >= ft_abs(dy))
		steps = ft_abs(dx);
	else
		steps = ft_abs(dy);
	dx = dx / steps;
	dy = dy / steps;
	dc = dc / steps;
	i = 0;
	while (i < steps)
	{

		color =  line->a.c * 25.0 + dc * (float)i *25.0 ;

		if (points_in_win(line, win_w, win_h))
			img_pixel_put(fb, line->a.x + dx * (float)i, line->a.y + dy * (float)i,
				rgb_to_int(
					color,
					255-line->a.y + dy * (float)i / -100,
					line->a.x + dx * (float)i / -100));
					// (float)(steps - i)/steps * 255,
					// (float)i/steps * 255,
					// (float)i/steps * 255));
		/* else
			img_pixel_put(fb, line->a.x + dx * i, line->a.y + dy * i, rgb_to_int((float)(steps - i)/steps * 255, (float)i/steps * 255, (float)i/steps * 255)); */
		i++;
	}

}

/*
void	draw_line(t_line *line, void *mlx, void *win)
{
	float	dx;
	float	dy;
	float	steps;
	int		i;

	dx = (line->b.x - line->a.x);
	dy = (line->b.y - line->a.y);
	if (ft_abs(dx) >= ft_abs(dy))
		steps = ft_abs(dx);
	else
		steps = ft_abs(dy);
	dx = dx / steps;
	dy = dy / steps;
	i = 0;
	while (i < steps)
	{
		mlx_pixel_put(mlx, win, line->a.x, line->a.y, 0xFFFFFF);
		line->a.x += dx;
		line->a.y += dy;
		i++;
	}
}*/

