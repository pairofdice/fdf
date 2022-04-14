/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:37:46 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/13 12:40:50 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FDF_H
# define FDF_H

#include <time.h>
// # include "../minilibx/mlx.h"
# include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 33
};

# define	WIN_W 900
# define	WIN_H 900

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	double	c;
}	t_point;

typedef struct s_line
{
	t_point a;
	t_point b;
}	t_line;

typedef struct s_dims
{
	float	x_max;
	float	y_max;
	float	z_min;
	float	z_max;
	float	c_min;
	float	c_max;
}	t_dims;

typedef struct s_frame_buffer
{
	void	*img;
	char	*data;
	char	*databg;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;

}	t_frame_buffer;
typedef struct s_transforms
{
	float rot;
	int shift_x;
	int shift_y;
	float scale;
	float zscale;
	int frame_n;
	int auto_rotate;
	int projection;
}	t_transforms;

typedef struct s_context
{
	void			*mlx;
	void			*win;
	t_frame_buffer	fb;
	//t_frame_buffer fb_bg;
	int				w;
	int				h;
	t_vec			map;
	t_point			max;
	t_transforms	t;
	clock_t			tic;
	int				draw_bg;
	t_dims			dims;
	int	mouse_x;
	int	mouse_y;
	int	r_mouse_dn;
}	t_context;


int		load_map(int fd, t_vec *map);
void	img_pixel_put(t_frame_buffer *fb, int x, int y, int color);
void	save_bg(t_frame_buffer *fb, int x, int y, int color);
void	checked_pixel_put(t_frame_buffer *fb, int x, int y, int color);
int		rgb_to_int(unsigned char r, unsigned char g, unsigned char b);
int		argb_to_int(unsigned char a, unsigned char r, unsigned char g, unsigned char b);
void	draw_line(t_line *line, t_context *ctx);
void	background(t_frame_buffer *fb, int win_w, int win_h);
void	blank(t_frame_buffer *fb, int win_w, int win_h);
void	model_to_world(t_point *p, t_point *max);
void	world_to_view(t_point *p, int win_w, int win_h);
void	draw_map(t_context *ctx);
void	isometric(t_point *p);
void	dimetric(t_point *p);
void	scroll(t_point *p);
void	top_view(t_point *p);
void	rotate(t_point *p, float rot);
void	scale(t_point *p, float multiplier);
void	zscale(t_point *p, float multiplier);
void	translate(t_point *p, int x, int y);
int		draw_frame(t_context *ctx);
void	help_text(t_context *ctx);

void	init_context(t_context *ctx);
int		handle_args(int argc, char **argv, t_vec *map);
int		on_keypress(int key_nb, t_context *ctx);
int		on_mouse_down(int button, int x, int y, t_context *ctx);
int		on_mouse_up(int button, int x, int y, t_context *ctx);
int		on_mouse_move(int x, int y, t_context *ctx);
int		fdf_close(t_context *vars);
void	max_dims(t_vec *map, t_point *max);
void	set_z_range(t_context *ctx, int i);
void	switch_auto_rotation(t_context *ctx);
//void print_map(t_point *p);

#endif
