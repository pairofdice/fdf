/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:21:31 by jsaarine          #+#    #+#             */
/*   Updated: 2021/11/22 17:40:32 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*freshness;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	freshness = (char *)malloc(sizeof(*s) * (len + 1));
	if (!freshness)
		return (NULL);
	while (i < len)
	{
		freshness[i] = (*f)((char)s[i]);
		i++;
	}
	freshness[i] = '\0';
	return (freshness);
}
