/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 17:35:15 by avallete          #+#    #+#             */
/*   Updated: 2015/02/18 12:52:51 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_splitdel(char **split)
{
	int i;

	i = 0;
	if (split)
	{
		while (((split)[i]) != NULL)
			i++;
		while (i > 0)
			free(((split)[i--]));
		if ((split[i]))
			free(((split)[i]));
		free(split);
		split = NULL;
	}
}
