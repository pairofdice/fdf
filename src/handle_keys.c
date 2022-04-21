/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:48:43 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/21 16:03:53 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_keys_b(int key_nb, t_context *ctx)
{
	if (key_nb == KEY_MB_W || key_nb == KEY_W)
		ctx->t.shift_y -= 10;
	if (key_nb == KEY_MB_B || key_nb == KEY_B)
		switch_auto_rotation(ctx);
	if (key_nb == KEY_MB_P || key_nb == KEY_P)
	{
		ctx->t.projection++;
		ctx->t.projection %= NUM_PROJ + 1;
	}
	if (key_nb == KEY_MB_Z || key_nb == KEY_Z)
		reset(ctx);
	return (0);
}

int	on_keys_a(int key_nb, t_context *ctx)
{
	ft_putnbr(key_nb);
	ft_putchar('\n');
	if (key_nb == KEY_MB_ESC || key_nb == KEY_ESC)
		fdf_close(ctx);
	if (key_nb == KEY_MB_Q || key_nb == KEY_Q)
		ctx->t.rot -= 128.0;
	if (key_nb == KEY_MB_E || key_nb == KEY_E)
		ctx->t.rot += 128.0;
	if (key_nb == KEY_MB_R || key_nb == KEY_R)
		ctx->t.scale *= 1.1;
	if (key_nb == KEY_MB_F || key_nb == KEY_F)
		ctx->t.scale *= 0.9;
	if (key_nb == KEY_MB_T || key_nb == KEY_T)
		ctx->t.zscale += 0.02;
	if (key_nb == KEY_MB_G || key_nb == KEY_G)
		ctx->t.zscale -= 0.02;
	if (key_nb == KEY_MB_D || key_nb == KEY_D)
		ctx->t.shift_x += 10;
	if (key_nb == KEY_MB_A || key_nb == KEY_A)
		ctx->t.shift_x -= 10;
	if (key_nb == KEY_MB_S || key_nb == KEY_S)
		ctx->t.shift_y += 10;
	return (0);
}
