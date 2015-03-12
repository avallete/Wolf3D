/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:41:36 by avallete          #+#    #+#             */
/*   Updated: 2014/11/10 11:12:05 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t e;

	i = 0;
	if (s2[0] == '\0' || s2 == NULL)
		return ((char*)s1);
	while (s1[i] != '\0' && i < n)
	{
		e = 0;
		if (s1[i] == s2[e])
		{
			while (s1[i + e] == s2[e])
			{
				if (!s2[e + 1] && (i + e) < n)
					return ((char*)s1 + i);
				e++;
			}
		}
		i++;
	}
	return (NULL);
}
