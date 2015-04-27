/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 11:11:07 by avallete          #+#    #+#             */
/*   Updated: 2014/11/12 12:50:40 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *list)
{
	t_list *begin;
	size_t i;

	begin = list;
	if (!list)
		return (0);
	i = 0;
	while (begin->next)
	{
		begin = begin->next;
		i++;
	}
	return (i);
}
