/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:41:36 by avallete          #+#    #+#             */
/*   Updated: 2014/11/10 12:21:31 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_sttrcpy(char *dest, const char *src, size_t i, size_t n)
{
	unsigned int c;

	c = 0;
	while (c < n)
	{
		dest[c] = src[i];
		i++;
		c++;
	}
	dest[n] = '\0';
	return (dest);
}

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *scop;

	if (s == NULL)
		return (NULL);
	if ((scop = ((char*)malloc(sizeof(char) * len + 1))))
	{
		scop = ft_sttrcpy(scop, s, start, len);
		return (scop);
	}
	return (scop);
}
