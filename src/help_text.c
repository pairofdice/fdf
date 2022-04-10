/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:35:51 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/10 15:23:31 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void help_text(t_context *ctx)
{

	mlx_string_put (ctx->mlx, ctx->win, 20, 20, 0xFFFFFF, "Move:           W, A, S, D" );
	mlx_string_put (ctx->mlx, ctx->win, 20, 30, 0xFFFFFF, "Zoom:           R, F" );
	mlx_string_put (ctx->mlx, ctx->win, 20, 40, 0xFFFFFF, "Height mltplr:  T, G" );
	mlx_string_put (ctx->mlx, ctx->win, 20, 50, 0xFFFFFF, "Rotate:         Q, E" );
	clock_t toc;
	toc = clock();
	printf("Elapsed: %f seconds\n", (double)(toc - ctx->tic) / CLOCKS_PER_SEC);
	//ft_putstr(ft_itoa((int)(toc - ctx->tic )/ CLOCKS_PER_SEC));
	//ft_putchar('\n');
	ctx->tic = toc;
	/*
	mlx_string_put (ctx->mlx, ctx->win, 20, 20, 0xFFFFFF, "" );
	mlx_string_put (ctx->mlx, ctx->win, 20, 20, 0xFFFFFF, "" );
	mlx_string_put (ctx->mlx, ctx->win, 20, 20, 0xFFFFFF, "" );
	mlx_string_put (ctx->mlx, ctx->win, 20, 20, 0xFFFFFF, "" );
	*/
}
