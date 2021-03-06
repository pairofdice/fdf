/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:36:42 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/17 23:30:43 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_point *p)
{
	float	x;
	float	y;
	float	z;

	x = p->x;
	y = p->y;
	z = p->z;
	p->x = (x - y) * COS_30;
	p->y = -z + (x + y) * SIN_30;
}

void	dimetric(t_point *p)
{
	float	x;
	float	y;
	float	z;

	x = p->x;
	y = p->y;
	z = p->z;
	p->x = x * COS_7 + y * COS_42 / 2.0;
	p->y = -z + y * SIN_42 / 2.0 - x * SIN_7;
}

void	scroll(t_point *p)
{
	float	x;
	float	y;
	float	z;

	x = p->x;
	y = p->y;
	z = p->z;
	p->x = x + 0.6 * y * COS_30;
	p->y = -z + 0.6 * y * SIN_30;
}

void	project(t_context *ctx, t_point *p)
{
	void	(*fn_ptrs[NUM_PROJ])(t_point *p);

	fn_ptrs[0] = isometric;
	fn_ptrs[1] = dimetric;
	fn_ptrs[2] = scroll;
	fn_ptrs[3] = top_view;
	fn_ptrs[4] = side_view;
	fn_ptrs[5] = perspective;
	if (ctx->t.projection < NUM_PROJ)
		(*fn_ptrs[ctx->t.projection])(p);
}
