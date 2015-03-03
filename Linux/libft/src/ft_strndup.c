/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 11:15:04 by avallete          #+#    #+#             */
/*   Updated: 2015/01/03 13:10:13 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strndup(const char *s, size_t n)
{
	char	*scop;

	if ((scop = ((char*)malloc(sizeof(char) * n))))
	{
		ft_strncpy(scop, s, n);
		scop[n] = '\0';
		return (scop);
	}
	return (NULL);
}
