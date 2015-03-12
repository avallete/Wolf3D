/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 12:30:47 by avallete          #+#    #+#             */
/*   Updated: 2014/11/10 12:41:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list *begin;

	begin = *alst;
	if (new)
	{
		while (begin->next != NULL)
			begin = begin->next;
		begin->next = new;
		new->next = NULL;
	}
}
