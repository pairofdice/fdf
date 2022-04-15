/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:36:42 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/14 22:09:07 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_point *p)
{
	float x;
	float y;
	float z;

	x = p->x;
	y = p->y;
	z = p->z;
	p->x = (x - y) * 0.8660 ;
	p->y = -z + (x + y) * 0.5 ;
}

void	dimetric(t_point *p)
{
	float x;
	float y;
	float z;

	x = p->x;
	y = p->y;
	z = p->z;
	p->x = x * 0.9925461 + y * 0.74314482547 / 2.0;
	p->y = -z + y * 0.669 / 2.0 - x * 0.1218693434;
}

void	scroll(t_point *p)
{
	float x;
	float y;
	float z;

	x = p->x;
	y = p->y;
	z = p->z;
	p->x = x + 0.6 * y * 0.81915204428;
	p->y = -z + 0.6 * y * 0.57357643635;
}

void	top_view(t_point *p)
{
	float x;
	float y;
	float z;

	x = p->x;
	y = p->y;
	z = p->z;
	p->x = x + y / 4.0;
	p->y = -z + y / 2.0;
}

void	side_view(t_point *p)
{
	float x;
	float y;
	float z;

	x = p->x;
	y = p->y;
	z = p->z;
	p->x = x + y / 2.0;
	p->y = -z + y / 4.0;
}

void	perspective(t_point *p)
{
	if (p->y < 2)
	{
		p->x /= 1.0 - p->y / 2.0;
		p->z /= 1.0 - p->y / 2.0;
		p->y /= 1.0 - p->y / 2.0;
		p->y -= p->z;
	}
}

void	project(t_context *ctx, t_point *p)
{
	void (*fn_ptrs[NUM_PROJ]) (t_point *p);

	fn_ptrs[0] = isometric;
	fn_ptrs[1] = dimetric;
	fn_ptrs[2] = scroll;
	fn_ptrs[3] = top_view;
	fn_ptrs[4] = side_view;
	fn_ptrs[5] = perspective;

	if (ctx->t.projection < NUM_PROJ)
		(*fn_ptrs[ctx->t.projection])(p);
}
