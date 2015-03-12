/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newrect_sdl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 09:25:41 by avallete          #+#    #+#             */
/*   Updated: 2015/03/12 10:30:09 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

SDL_Rect	ft_newrect_sdl(int x, int y, size_t width, size_t hight)
{
	SDL_Rect new;

	new.x = x;
	new.y = y;
	new.w = width;
	new.h = hight;
	return (new);
}
