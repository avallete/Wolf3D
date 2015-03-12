/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:13:55 by avallete          #+#    #+#             */
/*   Updated: 2015/02/14 18:47:51 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_tabstrcmp(char **tab, char *str, size_t size)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (ft_strncmp(tab[i], str, size) == 0)
			return (i);
		i++;
	}
	return (-1);
}
