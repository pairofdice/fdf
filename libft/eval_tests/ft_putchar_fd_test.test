/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:38:12 by jsaarine          #+#    #+#             */
/*   Updated: 2021/11/05 12:24:27 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <fcntl.h>

int	main(void)
{
	char	c;
	int		fd;

	fd = open("test", O_CREAT | O_TRUNC | O_RDWR);
	c = 'a';
	while (c <= 'z')
	{
		ft_putchar_fd(c, 1);
		c++;
	}
	ft_putchar_fd('\n', 1);
	c = 'a';
	while (c <= 'z')
	{
		ft_putchar_fd(c, 2);
		c++;
	}
	ft_putchar_fd('\n', 2);
}
