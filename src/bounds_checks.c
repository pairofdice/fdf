/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:07:15 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/22 18:07:44 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	neither_point_in_window(t_line *l, t_context *ctx)
{
	if ((l->a.x < 0 && l->b.x < 0)
		|| (l->a.y < 0 && l->b.y < 0)
		|| (l->a.x >= ctx->w && l->b.x >= ctx->w)
		|| (l->a.y >= ctx->h && l->b.y >= ctx->h))
	{
		return (1);
	}
	return (0);
}

int	points_in_window(t_line *l, t_context *ctx)
{
	if (l->a.x < 0 || l->a.y < 0 || l->a.x >= ctx->w || l->a.y >= ctx->h)
		return (0);
	if (l->b.x < 0 || l->b.y < 0 || l->b.x >= ctx->w || l->b.y >= ctx->h)
		return (0);
	return (1);
}