/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:45:05 by jsaarine          #+#    #+#             */
/*   Updated: 2021/11/22 17:46:45 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_spacetabnewline(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s)
{
	size_t	sstart;
	size_t	send;

	if (!s)
		return (NULL);
	sstart = 0;
	while (is_spacetabnewline(s[sstart]))
		sstart++;
	send = ft_strlen(s);
	while ((is_spacetabnewline(s[send]) || s[send] == '\0') && sstart != send)
		send--;
	return (ft_strsub(s, sstart, send - sstart + 1));
}
