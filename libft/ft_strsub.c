/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:53:29 by jsaarine          #+#    #+#             */
/*   Updated: 2021/11/22 17:45:27 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*freshness;
	size_t	i;

	if (!s)
		return (NULL);
	freshness = (char *)malloc(sizeof(char) * (len + 1));
	if (!freshness)
		return (NULL);
	i = 0;
	while (i < len)
	{
		freshness[i] = s[start + i];
		i++;
	}
	freshness[i] = '\0';
	return (freshness);
}
