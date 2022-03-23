/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:37:46 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/23 17:00:24 by jsaarine         ###   ########.fr       */
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

typedef struct s_frame_buffer
{
	unsigned char		*data;
	unsigned long int	data_size;
	unsigned int		width;
	unsigned int		height;
}	t_frame_buffer;

int load_map(char *filename, t_vec *map);
#endif
