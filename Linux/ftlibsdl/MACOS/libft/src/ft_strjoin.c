/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:41:36 by avallete          #+#    #+#             */
/*   Updated: 2014/11/05 10:26:13 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenjoin(char const *s1, char const *s2)
{
	size_t a;
	size_t b;

	a = 0;
	b = 0;
	if (s1 != NULL)
	{
		while (s1[a] != '\0')
			a++;
	}
	if (s2 != NULL)
	{
		while (s2[b] != '\0')
			b++;
	}
	return (a + b);
}

static void		ft_strcpjoin(char const *s1, char const *s2, char *result)
{
	size_t a;
	size_t i;

	i = 0;
	a = 0;
	if (s1 != NULL)
	{
		while (s1[a] != '\0')
		{
			result[i] = s1[a];
			a++;
			i++;
		}
	}
	if (s2 != NULL)
	{
		a = 0;
		while (s2[a] != '\0')
		{
			result[i] = s2[a];
			a++;
			i++;
		}
		result[i] = '\0';
	}
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char *result;

	result = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 != NULL || s2 != NULL)
	{
		result = (char*)malloc(sizeof(char) * (ft_lenjoin(s1, s2)) + 1);
		ft_strcpjoin(s1, s2, result);
	}
	return (result);
}
