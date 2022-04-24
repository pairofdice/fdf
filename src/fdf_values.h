/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_values.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:50:24 by jsaarine          #+#    #+#             */
/*   Updated: 2022/04/24 23:29:22 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_VALUES_H
# define FDF_VALUES_H

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
	NUM_HINTS = 9,
	NUM_COLORS = 4,
	Z_LIMIT = 1024,
	KEY_MB_ESC = 65307,
	KEY_MB_W = 119,
	KEY_MB_A = 97,
	KEY_MB_S = 115,
	KEY_MB_D = 100,
	KEY_MB_Q = 113,
	KEY_MB_E = 101,
	KEY_MB_R = 114,
	KEY_MB_F = 102,
	KEY_MB_T = 116,
	KEY_MB_G = 103,
	KEY_MB_P = 112,
	KEY_MB_Z = 122,
	KEY_MB_B = 98,
	KEY_MB_C = 99,
	KEY_MB_N = 110,
	KEY_ESC = 53,
	KEY_Q = 12,
	KEY_E = 14,
	KEY_R = 15,
	KEY_F = 3,
	KEY_T = 17,
	KEY_G = 5,
	KEY_D = 2,
	KEY_A = 0,
	KEY_S = 1,
	KEY_W = 13,
	KEY_B = 11,
	KEY_P = 35,
	KEY_Z = 6,
	KEY_C = 0,
	KEY_N = 0
};
# define COS_30 0.8660254
# define SIN_30 0.5
# define COS_42 0.7431448
# define SIN_42 0.6691306
# define SIN_7 0.1218693
# define COS_7 0.9925461
# define INIT_SCALE 4.0

#endif
