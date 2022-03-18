/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:14:02 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/17 19:34:10 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>

void	ft_putnbr(int n);
void draw_line(int x0, int y0, int x1, int y1)
{
	int		s;
	int		t_step;
	float	error;

	if (x0 > x1)
	{
		s = x1;
		x1 = x0;
		x0 = s;
		s = y1;
		y1 = y0;
		y0 = s;
	}
	s = x0;

	if (y0 < y1)
		t_step = 1;
	else
		t_step = -1;
	error = w / 2;
}

void dda(int x0, int y0, int x1, int y1)
{
	// find leftmost point
	// find slope
	// if slope is greater than 1 reverse x, y and take inverse of slope
	float	m;
	int		dx;
	int		dy;

	set_left(&x0, &y0, &x1, &y1);
	dx = x1 - x0;
	dy = y1 - y0;
	m = dy / dx;
	if (abs(dx) >= abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
	dx = dx / step;
	dy = dy / step;
	x = x1;
	y = y1;
	i = 1;

	while (i <= step) {
		putpixel(x, y, 5);
		x = x + dx;
		y = y + dy;
		i++;
  }
}
	//	dy=m*dx and dx=dy/m

void	set_left(int *x0, int *y0, int *x1, int *y1)
{
	int	temp;

	if (x0 > x1)
	{
		temp = *x0;
		*x0 = *x1;
		*x1 = temp;
		temp = *y0;
		*y0 = *y1;
		*y1 = temp;
	}
}


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int deal_key(int key_nb, void *param)
{
	ft_putnbr(key_nb);
	ft_putchar('\n');
	return (0);
}

void	ft_putnbr(int n)
{
	if (n < 0 )
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			ft_putnbr(147483648);
			return ;
		}
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar('0' + n);
}


int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;


	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 640, 480, "Machine State");
	i = 100;
	while (i < 150)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 100, i, 0xFFFFFF);
		i++;
	}
	i = 100;
	while (i < 150)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 150, i, 0xFFFFFF);
		i++;
	}
	i = 100;
	while (i < 150)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, 200, 0xFFFFFF);
		i++;
	}
	int		mlx_string_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );
	mlx_string_put (mlx_ptr, win_ptr, 300, 300, 0xE3FC03, "How you doin?" );
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);

	return (0);
}
