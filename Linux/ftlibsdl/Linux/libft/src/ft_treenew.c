/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 11:45:02 by avallete          #+#    #+#             */
/*   Updated: 2014/11/12 11:54:32 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_memcpyy(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
	return (dest);
}

t_tree			*ft_treenew(void *content, size_t content_size)
{
	t_tree	*first;
	void	*value;

	if (!(first = (t_tree*)malloc(sizeof(t_tree))))
		return (NULL);
	if (content == NULL)
	{
		first->content = NULL;
		first->content_size = 0;
	}
	else
	{
		value = ft_memalloc(content_size);
		value = ft_memcpyy(value, content, content_size);
		first->content = value;
		first->content_size = content_size;
	}
	first->father = NULL;
	first->right = NULL;
	first->left = NULL;
	return (first);
}
