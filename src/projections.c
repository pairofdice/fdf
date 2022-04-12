/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:36:42 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/12 17:15:33 by jsaarine         ###   ########.fr       */
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
	p->x = (x - y) * 0.5235988 ; //0.5235988 cos(30)
	p->y = -z + (x + y) * 0.523598 ; //0.523598 sin(30)
}

void	dimetric(t_point *p)
{
	float x;
	float y;
	float z;

	x = p->x;
	y = p->y;
	z = p->z;
	p->x = x * cos(0.9925461) + (y * 0.74314482547) / 2.0;
	//p->x = (x - y) * 0.5235988 ;
	p->y = -z + (y * 0.669) / 2.0 - x * 0.1218693434;
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

/* void projecc(t_context *ctx, t_point *p)
{
	if (ctx->t.projection == 0)
	if (ctx->t.projection == 0)
	if (ctx->t.projection == 0)
	if (ctx->t.projection == 0)
	
}
 */
