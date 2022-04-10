/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:01:21 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/10 12:03:24 by jsaarine         ###   ########.fr       */
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

int	argb_to_int(unsigned char a, unsigned char r, unsigned char g, unsigned char b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

void	do_transforms(t_point *p, t_context *ctx)
{
	model_to_world(p, ctx->max);
	scale(p, ctx->t->scale);
	zscale(p, ctx->t->zscale);
	rotate(p, ctx->t->frame_n / 1000.0);
	isometric(p);
	world_to_view(p, ctx->w, ctx->h);
	translate(p, ctx->t->shift_x, ctx->t->shift_y);
}

void	draw_map(t_context *ctx)
{
	int		x;
	int		y;
	t_vec	*map_line;
	t_vec	*map_next;
	t_line	line;

	y = 0;
	while (y < ctx->map->len - 1)
	{
		map_line = (t_vec *)vec_get(ctx->map, y);
		map_next = (t_vec *)vec_get(ctx->map, y + 1);
		x = 0;
		if (map_next)
		{
			while (x < map_line->len - 1)
			{
				t_point p1 = *(t_point *) vec_get(map_line, x);
				t_point p2 = *(t_point *) vec_get(map_line, x + 1);
				t_point p3 = *(t_point *) vec_get(map_next, x);

				do_transforms(&p1, ctx);
				line.a = p1;
				do_transforms(&p2, ctx);
				line.b = p2;
				draw_line(&line, ctx);
				do_transforms(&p3, ctx);
				line.b = p3;
				draw_line(&line, ctx);
				if (x == map_line->len - 2)
				{
					p3 = *(t_point *) vec_get(map_next, x + 1);
					do_transforms(&p3, ctx);
					line.a = p2;
					line.b = p3;
					draw_line(&line, ctx);
				}
				if (y == ctx->map->len - 2)
				{
					p2 = *(t_point *) vec_get(map_next, x + 1);
					p3 = *(t_point *) vec_get(map_next, x);
					do_transforms(&p2, ctx);
					do_transforms(&p3, ctx);
					line.a = p3;
					line.b = p2;
					draw_line(&line, ctx);
				}
				x++;
			}
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

int	draw_frame(void *context)
{
	t_context ctx;

	ctx = *(t_context *)context;
	//ctx.t->frame_n++;
	art_project(ctx.fb, ctx.w, ctx.h);
	draw_map(context);
	mlx_put_image_to_window(ctx.mlx, ctx.win, ctx.fb->img, 0, 0);
	return (1);
}
void	set_points(t_point *p, t_point *d, t_line *line)
{
	*p = line->a;
	d->c = (line->b.c - line->a.c);
	d->x = (line->b.x - line->a.x);
	d->y = (line->b.y - line->a.y);
}

void	draw_line(t_line *line, t_context *ctx)
{
	t_point d;
	t_point p;
	float	steps;
	unsigned char color;
	int		i;

	set_points(&p, &d, line);
	if (ft_abs(d.x) > ft_abs(d.y))
		steps = ft_abs(d.x);
	else
		steps = ft_abs(d.y);
	d.x = d.x / steps;
	d.y = d.y / steps;
	d.c = d.c / steps;
	i = 0;
	while (i < steps)
	{
		color =  line->a.c * 25.0 + d.c * (float)i *25.0 ;
		checked_pixel_put(ctx->fb, round(p.x), round(p.y),
				rgb_to_int(color,
					125-sin(((float)line->a.y +
					ctx->t->frame_n )/50.0) * 80 + d.y * (float)i / -100,
					125+sin(((float)line->a.x +
					ctx->t->frame_n )/60.0) * 80 + d.x * (float)i / -100));
		p.x += d.x;
		p.y += d.y;
		i++;
	}
}
