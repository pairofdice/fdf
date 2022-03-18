/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:10:00 by jsaarine          #+#    #+#             */
/*   Updated: 2021/11/26 13:47:41 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!lst)
		return (NULL);
	new = f(lst);
	if (lst->next)
	{
		new->next = ft_lstmap(lst->next, f);
		if (!new->next)
		{
			free(new->content);
			free(new);
			return (NULL);
		}
	}
	return (new);
}
