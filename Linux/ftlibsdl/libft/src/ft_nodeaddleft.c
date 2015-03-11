/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeaddleft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 12:03:10 by avallete          #+#    #+#             */
/*   Updated: 2014/11/12 12:09:40 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_nodeaddleft(t_tree *new, t_tree **tree)
{
	t_tree *begin;

	begin = *tree;
	while (begin->left)
		begin = begin->left;
	begin->left = new;
	new->father = begin;
}
