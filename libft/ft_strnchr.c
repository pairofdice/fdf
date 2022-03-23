/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:20:58 by jsaarine          #+#    #+#             */
/*   Updated: 2022/02/16 11:21:16 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, size_t n)
{
	int	len;
	int	i;

	if (n == 0)
		return (0);
		i = 0;
	len = ft_strlen(s);
	while (i <= len && n)
	{
		if (s[i] == (char) c)
			return ((char *)s + i);
		i++;
		n--;
	}
	return (NULL);
}
