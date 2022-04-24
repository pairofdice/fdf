/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:37:46 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/24 23:49:01 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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
int		rgb_to_int(t_point c);
void	draw_line(t_line *line, t_context *ctx);
void	colorslide(t_frame_buffer *fb);
void	blank(t_frame_buffer *fb);
void	copy_bg(t_frame_buffer *fb);
void	draw_map(t_context *ctx);
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
void	switch_auto_rotation(t_context *ctx);
void	isometric(t_point *p);
void	dimetric(t_point *p);
void	scroll(t_point *p);
void	scale_rotate(t_point *p, t_context *ctx);
void	model_to_world_per_point(t_point *p, t_context *ctx);
void	world_to_view(t_point *p, int x, int y);
void	do_transforms(t_point *p, t_context *ctx);
void	project(t_context *ctx, t_point *p);
void	top_view(t_point *p);
void	side_view(t_point *p);
void	perspective(t_point *p);
void	switch_projection(t_context *ctx);
void	reset(t_context *ctx);
int		points_in_window(t_line *l, t_context *ctx);
int		neither_point_in_window(t_line *l, t_context *ctx);
void	set_color(t_point *color, t_deltas *deltas, t_line *l, t_context *ctx);
void	rainbow_color(t_point *color, t_point *p, t_context *ctx);
void	rainbow_z_color(t_point *color, t_point *p, t_context *ctx);
void	black_white(t_point *color, t_point *p, t_context *ctx);
void	red_blue(t_point *color, t_point *p, t_context *ctx);

#endif
