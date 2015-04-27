/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 13:01:02 by avallete          #+#    #+#             */
/*   Updated: 2015/04/01 13:01:03 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_printtab(int *tab, int max)
{
	int i;

	i = 0;
	while (i < max)
		ft_printf("tab [%d][%d]\n", i, tab[i]), i++;
}
