/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:35:51 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/24 23:53:58 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	help_text(t_context *ctx)
{
	char	*hints[NUM_HINTS];
	int		i;

	hints[0] = "Move:     W, A, S, D or Mouse2";
	hints[1] = "Zoom:     R, F";
	hints[2] = "Height:   T, G or Mouse1";
	hints[3] = "Rotate:   Q, E";
	hints[4] = "Auto-rot: B";
	hints[5] = "Project.: P";
	hints[6] = "Reset:    Z";
	hints[7] = "Color:    C";
	hints[8] = "BG:       N";
	i = 0;
	while (i < NUM_HINTS)
	{
		mlx_string_put(ctx->mlx, ctx->win, 20, 20 + i * 13, 0xFFFFFF, hints[i]);
		i++;
	}
}
