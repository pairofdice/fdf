/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:58:16 by jsaarine          #+#    #+#             */
/*   Updated: 2021/11/26 15:29:19 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_strjoinloops(char const *s1, char const *s2, char **freshness)
{
	int	i;
	int	s1len;
	int	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	while (i < s1len)
	{
		(*freshness)[i] = s1[i];
		i++;
	}
	while ((i - s1len) < s2len)
	{
		(*freshness)[i] = s2[i - s1len];
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*freshness;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	freshness = (char *)malloc(sizeof(char) * (len + 1));
	if (!freshness)
		return (NULL);
	ft_strjoinloops(s1, s2, &freshness);
	freshness[len] = '\0';
	return (freshness);
}
