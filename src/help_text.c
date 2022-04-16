/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:35:51 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/15 22:45:59 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void put_hints(t_context *ctx, char **hints)
{
	int i;

	i = 0;
	while (*hints)
	{
		mlx_string_put(ctx->mlx, ctx->win, 20, 20 + i, 0xFFFFFF, *hints);
		i += 13;
		hints++;
	}
}

void	help_text(t_context *ctx)
{
	char *hints[10];

	hints[0] = "Move:     W, A, S, D";
	hints[1] = "Zoom:     R, F";
	hints[2] = "Height:   T, G";
	hints[3] = "Rotate:   Q, E";
	hints[4] = "Auto-rot: B";
	hints[5] = "Project.: P";
	hints[7] = "Reset:    Z";
	hints[8] = 0;
	put_hints(ctx, hints);
	clock_t toc;
	toc = clock();
	// printf("FPS: %f\n", 1.0 / ((double)(toc - ctx->tic) / CLOCKS_PER_SEC));
	ctx->tic = toc;
}
