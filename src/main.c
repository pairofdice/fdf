/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:14:02 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/30 16:31:02 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../minilibx/mlx.h" */
#include "fdf.h"
#include <stdlib.h>

#include <unistd.h>

/* void	set_left(t_line *line)
{
	int	temp;

	if (line->a.x > line->b.x)
	{
		temp = line->a.x;
		line->a.x = line->b.x;
		line->b.x = temp;
		temp = line->a.y;
		line->a.y = line->a.y;
		line->a.y = temp;
	}
}
 */

/* void	draw_pixel(t_point point, t_frame_buffer *fb, unsigned int color)
{
	unsigned long    i;

	i = 4 * ((unsigned int)point.y * fb->width + (unsigned int)point.x);



}

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
int clamp(int nb, int boundary)
{
	if (nb > boundary)
		nb = boundary;
	return (nb);
}

size_t	max_width(t_vec *map)
{
	int i;
	size_t max;

	i = 0;
	max = 0;
	while (i < map->len)
	{
		if (max < ((t_vec *)vec_get(map, i))->len)
			max = ((t_vec *)vec_get(map, i))->len;
		i++;
	}
	return (max);
}

void	draw_map(t_frame_buffer* fb, t_vec *map, int win_w, int win_h)
{
	size_t map_h;
	size_t map_w;
	float x_step;
	float y_step;
	float margin;
	int x;
	int y;
	t_vec	*map_line;
	t_line 	line;

	x = map->len;
	y = max_width(map);
	y = 0;
	while (y < map_h - 1)
	{
		map_line = (t_vec *)vec_get(map, y);
		x = 0;
		while (x < map_w - 1)
		{
			//draw_line();
			x++;
		}
		y++;
	}
}

/*
	normalize map coordinates from (0, something) to (-1, 1)
 */
void model_to_world(t_vec *map, t_point *max)
{

	t_vec	*line_vec;
	size_t	r;
	r = 0;
	size_t k;
	t_point *p;
	 while (r < map->len)
	{
		line_vec = vec_get(map, r++);
		k = 0;
		while (k < line_vec->len)
		{
			p = (t_point *)vec_get(line_vec, k++);
			/*
			p->x = 2 * p->x / max->x - 1;
			p->y = 2 * p->y / max->y - 1; */
		}
	}
}

void world_to_view()
{

}

void art_project(t_frame_buffer *fb, int win_w, int win_h)
{
	int y = 0;
	int xc;
	int yc;
	int xyc;
	while (y < win_h)
	{
		int x = 0;
		while (x < win_w)
		{
			xc = (float)x/(float)win_w * 255;
			yc = (float)y/(float)win_h * 255;
			xyc = (float)(x + y)/(float)4 ;
			img_pixel_put(fb, x, y, rgb_to_int(xc % 51 * 5, yc, (float)(xc + yc) / (float)2));
			x++;
		}
		y++;
	}
}

int rgb_to_int(unsigned char r, unsigned char g, unsigned char b)
{
	int color;

	color = b;
	color = color | (int)g << 8;
	color = color | (int)r << 16;
	return (color);
}

void	draw_line(t_line *line, t_frame_buffer *fb)
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
		img_pixel_put(fb, line->a.x, line->a.y, rgb_to_int(255, 255, 255));
		line->a.x += dx;
		line->a.y += dy;
		i++;
	}
}

int on_keypress(int key_nb, void *param)
{
	ft_putnbr(key_nb);
	ft_putchar('\n');
	if (key_nb == 53)
		exit (1);
	if (param)
	{}
	return (1);
}


/* int		on_mousepress(int button,int x,int y,void *param)
{
	return (1);
} */

void	img_pixel_put(t_frame_buffer *fb, int x, int y, int color)
{
	char	*dst;

	dst = fb->data + (y * fb->line_length + x * (fb->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void print_map(t_vec * map)
{
	t_vec	*line_vec;
	size_t	r;
	r = 0;
	size_t k;
	t_point p;
	 while (r < map->len)
	{
		line_vec = vec_get(map, r++);
		//line_vec = (t_vec *)map->memory[r].memory;
		// ptr = &map->memory[r];
		//line_vec = (t_vec *) &map->memory[r];
		k = 0;
		while (k < line_vec->len)
		{
			p = *(t_point *)vec_get(line_vec, k++);
			ft_putnbr(p.x);
			ft_putchar('-');
			ft_putnbr(p.y);
			ft_putchar('-');
			ft_putnbr(p.z);
			ft_putchar('\t');
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int main()
{
	void	*mlx;
	void	*win;
 	int		i;
	 t_line	line1;
 	int mx;
	int my;
	int win_w;
	int win_h;
	t_vec	map;
	t_frame_buffer fb;
	int fd;


	win_w = 640;
	win_h = 480;
	mlx = mlx_init();
	fb.img = mlx_new_image(mlx, win_w, win_h);
	fb.data = mlx_get_data_addr(fb.img, &fb.bits_per_pixel, &fb.line_length, &fb.endian);
	win = mlx_new_window(mlx, win_w, win_h, "Machine State");
	art_project(&fb, win_w, win_h);

	fd = open("maps/10-2.fdf", O_RDONLY);
	load_map(fd, &map);
	print_map(&map);
	model_to_world(&map, (t_point *){win_w, win_h, 0});
	print_map(&map);


 	mx = win_w / 2;
	my = win_h / 2;


	line1 = (t_line){(t_point){mx+5, my+5, 0}, (t_point){mx + 50, my + 50, 0}};
	draw_line(&line1,  &fb);
	line1 = (t_line){(t_point){mx+5, my-5, 0}, (t_point){mx + 50, my - 50, 0}};
	draw_line(&line1,  &fb);
	line1 = (t_line){(t_point){mx-5, my+5, 0}, (t_point){mx - 50, my + 50, 0}};
	draw_line(&line1, &fb);
	line1 = (t_line){(t_point){mx-5, my-5, 0}, (t_point){mx - 50, my - 50, 0}};
	draw_line(&line1,  &fb);

	line1 = (t_line){(t_point){mx+5, my+5, 0}, (t_point){mx + 100, my + 50, 0}};
	draw_line(&line1,  &fb);
	line1 = (t_line){(t_point){mx+5, my-5, 0}, (t_point){mx + 50, my - 100, 0}};
	draw_line(&line1,  &fb);
	line1 = (t_line){(t_point){mx-5, my+5, 0}, (t_point){mx - 100, my + 50, 0}};
	draw_line(&line1,  &fb);
	line1 = (t_line){(t_point){mx-5, my-5, 0}, (t_point){mx - 50, my - 100, 0}};
	draw_line(&line1,  &fb);

	line1 = (t_line){(t_point){mx+5, my+5, 0}, (t_point){mx + 50, my + 100, 0}};
	draw_line(&line1,  &fb);
	line1 = (t_line){(t_point){mx+5, my-5, 0}, (t_point){mx + 100, my - 50, 0}};
	draw_line(&line1,  &fb);
	line1 = (t_line){(t_point){mx-5, my+5, 0}, (t_point){mx - 50, my + 100, 0}};
	mlx_string_put (mlx, win, 300, 300, 0xE3FC03, "How you doin?" );
	draw_line(&line1,  &fb);
	line1 = (t_line){(t_point){mx-5, my-5, 0}, (t_point){mx - 100, my - 50, 0}};
	draw_line(&line1,  &fb);

	mlx_put_image_to_window(mlx, win, fb.img, 0, 0);


	//int		mlx_string_put ( void *mlx, void *win, int x, int y, int color, char *string );
	mlx_key_hook(win, on_keypress, (void *)0);
	mlx_string_put (mlx, win, 260, 227, 0xE3FC03, "How you doin?" );
	mlx_loop(mlx);

	return (0);
}

/*
	t_img_state	img;

	void		*mlx;
	void		*win;
	int			i;



	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "Machine State");


	img.img = mlx_new_image(mlx, 1920, 1080);


	int		mlx_string_put ( void *mlx, void *win, int x, int y, int color, char *string );
	mlx_string_put (mlx, win, 300, 300, 0xE3FC03, "How you doin?" );
	mlx_key_hook(win, on_keypress, (void *)0);
	mlx_loop(mlx);




	t_line    line1;
	int mx;
	int my;
	int win_w;
	int win_h;
	win_w = 640;
	win_h = 480;

	i = 100;
	while (i < 150)
	{
		mlx_pixel_put(mlx, win, 100, i, 0xFFFFFF);
		i++;
	}
	mx = win_w / 2;
	my = win_h / 2;
	line1 = (t_line){(t_point){mx+5, my+5, 0}, (t_point){mx + 50, my + 50, 0}};
	draw_line(&line1,  mlx, win);
	line1 = (t_line){(t_point){mx+5, my-5, 0}, (t_point){mx + 50, my - 50, 0}};
	draw_line(&line1,  mlx, win);
	line1 = (t_line){(t_point){mx-5, my+5, 0}, (t_point){mx - 50, my + 50, 0}};
	draw_line(&line1,  mlx, win);
	line1 = (t_line){(t_point){mx-5, my-5, 0}, (t_point){mx - 50, my - 50, 0}};
	draw_line(&line1,  mlx, win);

	//int        mlx_string_put ( void *mlx, void *win, int x, int y, int color, char *string );
	mlx_key_hook(win, on_keypress, (void *)0);
	mlx_loop(mlx);
	return (0); */
