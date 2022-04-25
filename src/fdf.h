/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:37:46 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/25 15:10:30 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//# include "../minilibx/mlx.h"
# include "mlx.h"
# include "../libft/libft.h"
# include "fdf_values.h"
# include "fdf_structs.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

// background.c
void	colorslide(t_frame_buffer *fb);
void	copy_bg(t_frame_buffer *fb);
void	blank(t_frame_buffer *fb);
// bounds_check.c
int		neither_point_in_window(t_line *l, t_context *ctx);
int		points_in_window(t_line *l, t_context *ctx);
// color_maps.c
void	rainbow_color(t_point *color, t_point *p, t_context *ctx);
void	red_blue(t_point *color, t_point *p, t_context *ctx);
void	black_white(t_point *color, t_point *p, t_context *ctx);
void	rainbow_z_color(t_point *color, t_point *p, t_context *ctx);
// color.c
void	set_color(t_point *color, t_deltas *deltas, t_line *l, t_context *ctx);
int		rgb_to_int(t_point c);
// draw_map.c
void	draw_map(t_context *ctx);
// draw.c
int		draw_frame(t_context *ctx);
// handle_it.c
int		on_keypress(int key_nb, t_context *ctx);
int		fdf_close(t_context *vars);
int		on_mouse_down(int button, int x, int y, t_context *ctx);
int		on_mouse_move(int x, int y, t_context *ctx);
int		on_mouse_up(int button, int x, int y, t_context *ctx);
// handle_keys.c
int		on_keys_a(int key_nb, t_context *ctx);
int		on_keys_b(int key_nb, t_context *ctx);
// help_text.c
void	help_text(t_context *ctx);
// init.c
void	init_context(t_context *ctx);
void	reset(t_context *ctx);
void	set_z_range(t_context *ctx, double i);
void	max_dimensions(t_context *ctx);
// draw_line.c
void	draw_line(t_line *line, t_context *ctx);
// load.c
int		handle_args(int argc, char **argv, t_context *ctx);
int		load_map(int fd, t_context *ctx);
// pixel_put_color.c
void	checked_pixel_put(t_frame_buffer *fb, int x, int y, int color);
void	save_bg(t_frame_buffer *fb, int x, int y, int color);
void	img_pixel_put(t_frame_buffer *fb, int x, int y, int color);
// projections_more
void	top_view(t_point *p);
void	side_view(t_point *p);
void	perspective(t_point *p);
// projections.c
void	isometric(t_point *p);
void	dimetric(t_point *p);
void	scroll(t_point *p);
void	project(t_context *ctx, t_point *p);
// transforms.c
void	scale_rotate(t_point *p, t_context *ctx);
void	world_to_view(t_point *p, int x, int y);
void	model_to_world_per_point(t_point *p, t_context *ctx);
void	switch_auto_rotation(t_context *ctx);
void	do_transforms(t_point *p, t_context *ctx);

#endif
