/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fft_putnbr_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:44:08 by jsaarine          #+#    #+#             */
/*   Updated: 2021/11/06 18:06:46 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <fcntl.h>

int	main(void)
{
	int	fd;
	int i;

	fd = open("p2_tests/putnbr_fd_user_output", O_CREAT | O_TRUNC | O_RDWR);
	if (fd != -1)
	{
		i = -11;
		while (i < 12)
		{
			ft_putnbr_fd(i);
			ft_putchar_fd(' ');
			i++;
		}
		ft_putnbr_fd(0, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(1, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(-1, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(42, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(-42, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(4000, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(-4000, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(2147483647, fd);
		ft_putchar_fd('\n', fd);
		ft_putnbr_fd(-2147483648, fd);
		ft_putchar_fd('\n', fd);
	}
	i = -11;
	while (i < 12)
	{
		ft_putnbr_fd(i);
		ft_putchar_fd(' ');
		i++;
	}
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(1, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-1, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(42, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-42, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(4000, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-4000, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
