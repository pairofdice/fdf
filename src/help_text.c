/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:35:51 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/22 18:05:15 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	help_text(t_context *ctx)
{
	char	*hints[9];
	clock_t	toc;
	int		i;

	hints[0] = "Move:     W, A, S, D or Mouse2";
	hints[1] = "Zoom:     R, F";
	hints[2] = "Height:   T, G or Mouse1";
	hints[3] = "Rotate:   Q, E";
	hints[4] = "Auto-rot: B";
	hints[5] = "Project.: P";
	hints[6] = "Reset:    Z";
	i = 0;
	while (i < 7)
	{
		mlx_string_put(ctx->mlx, ctx->win, 20, 20 + i * 13, 0xFFFFFF, hints[i]);
		i++;
	}
	toc = clock();
	printf("FPS: %f\n", 1.0 / ((double)(toc - ctx->tic) / CLOCKS_PER_SEC));
	ctx->tic = toc;
}
