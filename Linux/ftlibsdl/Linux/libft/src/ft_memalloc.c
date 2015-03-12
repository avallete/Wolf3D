/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:41:35 by avallete          #+#    #+#             */
/*   Updated: 2014/11/10 10:55:11 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void *ft_memalloc(size_t size)
{
	void	*p;
	size_t	i;

	i = 0;
	if (size == 0)
		return (NULL);
	p = (void*)malloc(sizeof(void*) * size);
	if (p)
	{
		while (i != size)
			((char*)p)[i++] = 0;
		return (p);
	}
	return (NULL);
}
