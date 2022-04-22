/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:37:46 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/21 22:26:13 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <time.h>

# include "../minilibx/mlx.h"
//# include "mlx.h"
# include "../libft/libft.h"
# include "fdf_values.h"
# include "fdf_structs.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

int		load_map(int fd, t_context *ctx);
void	img_pixel_put(t_frame_buffer *fb, int x, int y, int color);
void	save_bg(t_frame_buffer *fb, int x, int y, int color);
void	checked_pixel_put(t_frame_buffer *fb, int x, int y, int color);
int		rgb_to_int(unsigned char r, unsigned char g, unsigned char b);
int		argb_to_int(unsigned char a,
			unsigned char r,
			unsigned char g,
			unsigned char b);
void	draw_line(t_line *line, t_context *ctx);
void	colorslide(t_frame_buffer *fb);
void	blank(t_frame_buffer *fb);
void	copy_bg(t_frame_buffer *fb);
void	model_to_world(t_context *ctx);
void	model_to_world_per_point(t_point *p, t_context *ctx);
void	world_to_view(t_point *p, int x, int y);
void	draw_map(t_context *ctx);
void	isometric(t_point *p);
void	dimetric(t_point *p);
void	scroll(t_point *p);
void	top_view(t_point *p);
//void	rotate(t_point *p, float rot);
void	scale_rotate(t_point *p, t_context *ctx);
void	scale(t_point *p, t_context *ctx);
//void	scale(t_point *p, float gen_multiplier, float height_multiplier);
void	translate(t_point *p, int x, int y);
int		draw_frame(t_context *ctx);
void	help_text(t_context *ctx);

void	init_context(t_context *ctx);
int		handle_args(int argc, char **argv, t_context *ctx);
int		on_keypress(int key_nb, t_context *ctx);
int		on_keys_a(int key_nb, t_context *ctx);
int		on_keys_b(int key_nb, t_context *ctx);
int		on_mouse_down(int button, int x, int y, t_context *ctx);
int		on_mouse_up(int button, int x, int y, t_context *ctx);
int		on_mouse_move(int x, int y, t_context *ctx);
int		fdf_close(t_context *vars);
void	max_dimensions(t_context *ctx);
void	set_z_range(t_context *ctx, double i);
void	set_color(t_point *color, t_point p, t_context *ctx);
void	switch_auto_rotation(t_context *ctx);
void	do_transforms(t_point *p, t_context *ctx);
void	project(t_context *ctx, t_point *p);
void	top_view(t_point *p);
void	side_view(t_point *p);
void	perspective(t_point *p);
void	switch_projection(t_context *ctx);
void	reset(t_context *ctx);
int		points_in_window(t_line *l, t_context *ctx);
int		neither_point_in_window(t_line *l, t_context *ctx);
float	interpolate(float a, float b, int i, int steps);
void	color_range_map(t_context *ctx);

//void print_map(t_point *p);

#endif
