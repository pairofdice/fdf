/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:05:14 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/03 12:25:45 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// 2d_x = (3d_x - 3d_z) * cos(30)
// 2d_z = -3d_y + (3d_x + 3d_z) * sin(30)
void isometric(t_vec *map)
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
			float x = p->x;
			float y = p->y;
			float z = p->z;
			p->x = (x - y) * 0.89444848138 ; //0.5235988 cos(30)
			p->y = -z + (x + y) * 0.44717101221 ; //0.523598 sin(30)

		}
	}
}

void rotate(t_vec *map, float rot)
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
			float x = p->x;
			float y = p->y;
			p->x = x * cos(rot) - y * sin(rot);
			p->y = y * cos(rot) + x * sin(rot);
		}
	}
}

void world_to_view(t_vec *map, int win_w, int win_h)
{
	t_vec	*line_vec;
	size_t	r;
	size_t k;
	t_point *p;
	int margin;

	r = 0;
	margin = 20;
	 while (r < map->len)
	{
		line_vec = vec_get(map, r++);
		k = 0;
		while (k < line_vec->len)
		{
			p = (t_point *)vec_get(line_vec, k++);
			p->x = (win_w/2.8) + p->x * (win_w / 4.0 + 1) ;
			p->y = (win_h/2) + p->y * (win_h / 4.0 + 1) ;
			p->z = p->z * 0.5;
		}
	}
}

/*
	normalize map coordinates from (0, something) to (-1, 1)
 */

void model_to_world(t_vec *map, t_point *max)
{
	t_vec	*line_vec;
	size_t	r;
	size_t k;
	t_point *p;

	r = 0;
	 while (r < map->len)
	{
		line_vec = vec_get(map, r++);
		k = 0;
		while (k < line_vec->len)
		{
			p = (t_point *)vec_get(line_vec, k++);
			p->x = p->x / (ft_max(max->x, max->y) - 1) * 2 - 1;
			p->y = p->y / (ft_max(max->x, max->y) - 1) * 2 - 1;
			p->z = p->z / 155.0;
		}
	}
}
