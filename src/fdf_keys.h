/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:50:24 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/16 14:43:47 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_KEYS_H
# define FDF_KEYS_H

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 33,
	WIN_W = 900,
	WIN_H = 900,
	NUM_PROJ = 6,
	Z_LIMIT = 256,
	KEYMB_ESC = 65307,
	KEYMB_W = 119,
	KEYMB_A = 97,
	KEYMB_S = 115,
	KEYMB_D = 100,
	KEYMB_Q = 113,
	KEYMB_E = 101,
	KEYMB_R = 114,
	KEYMB_F = 102,
	KEYMB_T = 116,
	KEYMB_G = 103,
	KEYMB_P = 112,
	KEYMB_Z = 122,
	KEYMB_B = 98,
};

#endif
