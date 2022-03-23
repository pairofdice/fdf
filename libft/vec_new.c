/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaarine <jsaarine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:03:42 by jsaarine          #+#    #+#             */
/*   Updated: 2022/03/23 14:52:00 by jsaarine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
	take a pointer to a t_vec and allocate len * elem_size bytes
	in the buffer as well as initialize its length and element size.
*/
int	vec_new(t_vec *src, size_t init_len, size_t elem_size)
{
	if (!src || elem_size == 0)
		return (-1);
	if (init_len == 0)
		src->memory = NULL;
	else
	{
		src->memory = (char *) malloc(init_len * elem_size);
		if (!src->memory)
			return (-1);
		ft_memset(src->memory, 0, init_len * elem_size);
	}
	src->len = 0;
	src->alloc_size = init_len * elem_size;
	src->elem_size = elem_size;
	return (1);
}
