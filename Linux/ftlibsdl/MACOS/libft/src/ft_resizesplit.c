/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resizesplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 12:06:32 by avallete          #+#    #+#             */
/*   Updated: 2015/02/18 12:52:35 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_resizesplit(char **src, size_t begin, size_t end)
{
	char	**new;
	int		size;
	int		i;

	i = 0;
	size = end - begin;
	size = FT_ABS(size);
	new = (char**)malloc(sizeof(char*) * size + 1);
	while (src[begin] && i < size)
		new[i] = ft_strdup(src[begin++]), i++;
	ft_splitdel(src);
	new[size] = NULL;
	return (new);
}
