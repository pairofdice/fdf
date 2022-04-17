/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections_more.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:36:42 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/17 23:30:59 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	top_view(t_point *p)
{
	float	x;
	float	y;
	float	z;

	x = p->x;
	y = p->y;
	z = p->z;
	p->x = x + y / 4.0;
	p->y = -z + y / 2.0;
}

void	side_view(t_point *p)
{
	float	x;
	float	y;
	float	z;

	x = p->x;
	y = p->y;
	z = p->z;
	p->x = x + y / 2.0;
	p->y = -z + y / 4.0;
}

void	perspective(t_point *p)
{
	if (p->y < 2.0)
	{
		p->x /= 1.0 - p->y / 2.0;
		p->z /= 1.0 - p->y / 2.0;
		p->y /= 1.0 - p->y / 2.0;
		p->y -= p->z;
	}
	else
	{
		p->y = 3;
	}
}
