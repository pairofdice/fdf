/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:35:51 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/11 21:49:38 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void put_hints(t_context *ctx, char **hints)
{
	int i;

	i = 0;
	while (*hints)
	{
		mlx_string_put(ctx->mlx, ctx->win, 20, 20 + i, 0xFFFFFF, *hints);
		i += 10;
		hints++;
	}
}
void	help_text(t_context *ctx)
{
	char *hints[7];

	hints[0] = "Move:  W, A, S, D";
	hints[1] = "Zoom:  R, F";
	hints[2] = "Height: T, G";
	hints[3] = "Rotate: Q, E";
	hints[4] = "Auto-rot: B";
	hints[5] = 0;
	put_hints(ctx, hints);

/*
	mlx_string_put(ctx->mlx, ctx->win, 20, 20, 0xFFFFFF, "Move:  W, A, S, D" );
	mlx_string_put(ctx->mlx, ctx->win, 20, 30, 0xFFFFFF, "Zoom:  R, F" );
	mlx_string_put(ctx->mlx, ctx->win, 20, 40, 0xFFFFFF, "Height: T, G" );
	mlx_string_put(ctx->mlx, ctx->win, 20, 50, 0xFFFFFF, "Rotate: Q, E" );
	mlx_string_put(ctx->mlx, ctx->win, 20, 50, 0xFFFFFF, "Auto-rot: B" );
	*/
	clock_t toc;
	toc = clock();
	printf("FPS: %f\n", 1.0 / ((double)(toc - ctx->tic) / CLOCKS_PER_SEC));
	ctx->tic = toc;
}
	//ft_putstr(ft_itoa((int)(toc - ctx->tic )/ CLOCKS_PER_SEC));
	//ft_putchar('\n');
	/*
	mlx_string_put (ctx->mlx, ctx->win, 20, 20, 0xFFFFFF, "" );
	mlx_string_put (ctx->mlx, ctx->win, 20, 20, 0xFFFFFF, "" );
	mlx_string_put (ctx->mlx, ctx->win, 20, 20, 0xFFFFFF, "" );
	mlx_string_put (ctx->mlx, ctx->win, 20, 20, 0xFFFFFF, "" );
	*/
