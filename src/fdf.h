/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:37:46 by jsaarine          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/22 12:50:59 by jsaarine         ###   ########.fr       */
=======
<<<<<<< HEAD:fdf.h
/*   Updated: 2022/03/22 12:27:19 by jsaarine         ###   ########.fr       */
=======
/*   Updated: 2022/03/21 17:34:03 by jsaarine         ###   ########.fr       */
>>>>>>> bf1a40fb35b3dcf2e9494c82ec474f554ead4acd:src/fdf.h
>>>>>>> 6d5017816879cb4810d7e1e065fe074456c492bd
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>


typedef struct s_context
{
	void	*mlx;
	void	*win;
	int		w;
	int		h;
}	t_context;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_line
{
	t_point a;
	t_point b;
}	t_line;

typedef struct s_img_state
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_state


#endif
