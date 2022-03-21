/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:37:46 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/21 17:34:03 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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


#endif








#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>


# define BUFF 546
# define MAX_TETRI 26

typedef struct s_piece
{
	long	offset [6];
	char	name;
	int		placed;
}	t_piece;

int		ft_map(int size, char **ptr);
int		ft_sqrt(int nb);
int		ft_isvalid(char **argv, char *buff, int *tetri_nb);
int		ft_chrcount(char *buff);
int		ft_adjpart(char *buff);
int		ft_parse(char *input, t_piece **tetri_set, int tetri_nb);
void	parse_piece(char *input, t_piece *piece);
int		ft_delete_tetri(t_piece **tetri_set, int i);
int		solve(t_piece **tetri_set, int min_size, int tetri_nb);
int		ft_search(t_piece **tetri_set, char *map, int size, int tetri_nb);
int		ft_place_piece(char *map, t_piece *tetri, int size);
int		ft_remove_piece(char **map, t_piece *piece);
int		all_pieces_placed(t_piece **tetri_set, int tetri_nb);

void	tetri_print(t_piece **tetri_set, int tetri_nb);

#endif
