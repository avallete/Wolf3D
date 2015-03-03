/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:41:35 by avallete          #+#    #+#             */
/*   Updated: 2014/11/08 19:20:53 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_len(int n, size_t *size, int *e)
{
	*size = 1;
	if (n >= 0)
	{
		*size = 0;
		n = -n;
	}
	*e = 1;
	while (n / *e < -9)
	{
		*e *= 10;
		*size += 1;
	}
}

char			*ft_itoa(int n)
{
	size_t	size;
	size_t	i;
	int		e;
	char	*result;

	ft_len(n, &size, &e);
	if ((result = (char*)malloc(sizeof(*result) * (size + 1))))
	{
		i = 0;
		if (n < 0)
		{
			result[i] = '-';
			i++;
		}
		if (n > 0)
			n = -n;
		while (e >= 1)
		{
			result[i++] = -(n / e % 10) + 48;
			e /= 10;
		}
		result[i] = '\0';
		return (result);
	}
	return (NULL);
}
