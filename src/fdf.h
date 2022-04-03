/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:37:46 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/03 11:22:51 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
// # include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

typedef struct s_context
{
	void	*mlx;
	void	*win;
	int		w;
	int		h;
}	t_context;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	float	c;
}	t_point;

typedef struct s_line
{
	t_point a;
	t_point b;
}	t_line;

typedef struct s_frame_buffer
{
	void	*img;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;

}	t_frame_buffer;


int		load_map(int fd, t_vec *map);
void	img_pixel_put(t_frame_buffer *fb, int x, int y, int color);
int		rgb_to_int(unsigned char r, unsigned char g, unsigned char b);
void	draw_line(t_line *line, t_frame_buffer *fb, int win_w, int win_h);
void	art_project(t_frame_buffer *fb, int win_w, int win_h);
void	model_to_world(t_vec *map, t_point *max);
void	world_to_view(t_vec *map, int win_w, int win_h);
void	draw_map(t_frame_buffer* fb, t_vec *map, int win_w, int win_h, t_point *max);
void isometric(t_vec *map);
void rotate(t_vec *map, float rot);

#endif
