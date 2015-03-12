/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeaddright.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 12:05:16 by avallete          #+#    #+#             */
/*   Updated: 2014/11/12 12:07:44 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_nodeaddright(t_tree *new, t_tree **tree)
{
	t_tree *begin;

	begin = *tree;
	while (begin->right)
		begin = begin->right;
	begin->right = new;
	new->father = begin;
}
