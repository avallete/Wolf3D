/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 13:11:37 by avallete          #+#    #+#             */
/*   Updated: 2015/04/01 14:55:58 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

static void	color_debug(t_ray *r, Uint32 *color)
{
	if (r->dir.x >= 0)
	{
		if (r->side == 0)
			*color = 0x8E44AD;
	}
	else
	{
		if (r->side == 0)
			*color = 0xF1C40F;
	}
	if (r->dir.y >= 0)
	{
		if (r->side == 1)
			*color = 0xC0392B;
	}
	else
	{
		if (r->side == 1)
			*color = 0x7F8C8D;
	}
}

static void	color_simple(t_ray *r, Uint32 *color)
{
	Uint8 *colors;

	colors = (Uint8*)&r->mapos.color;
	if (r->side == 0)
		*color = r->mapos.color;
	else
	{
		colors[0] - 25 > 0 ? (colors[0] -= 25) : 0;
		colors[1] - 25 > 0 ? (colors[1] -= 25) : 0;
		colors[2] - 25 > 0 ? (colors[2] -= 25) : 0;
		*color = r->mapos.color;
	}
}

void		define_color(t_game *e, t_ray *r, Uint32 *color, char mode)
{
	if (e)
	{
		if (mode)
			color_debug(r, color);
		else
			color_simple(r, color);
	}
}
