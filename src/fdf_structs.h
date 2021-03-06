/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:49:09 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/24 23:55:18 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

# include "fdf.h"

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	double	c;
}	t_point;

typedef struct s_deltas
{
	double	x;
	double	y;
	double	z;
	double	r;
	double	g;
	double	b;
}	t_deltas;

typedef struct s_line
{
	t_point	a;
	t_point	b;
}	t_line;

typedef struct s_dims
{
	float	w;
	float	h;
	double	z_min;
	double	z_max;
}	t_dims;

typedef struct s_frame_buffer
{
	void	*img;
	void	*imgbg;
	char	*data;
	char	*databg;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;

}	t_frame_buffer;

typedef struct s_transforms
{
	float	rot;
	int		shift_x;
	int		shift_y;
	float	scale;
	float	zscale;
	int		frame_n;
	int		auto_rotate;
	int		auto_rotate_rate;
	int		projection;
	int		perspective;
	int		color_map;
}	t_transforms;

typedef struct s_context
{
	void			*mlx;
	void			*win;
	t_frame_buffer	fb;
	int				w;
	int				h;
	t_vec			map;
	t_transforms	t;
	int				draw_bg;
	t_dims			dims;
	int				mouse_x;
	int				mouse_y;
	int				right_mouse_dn;
	int				left_mouse_dn;
}	t_context;

#endif
