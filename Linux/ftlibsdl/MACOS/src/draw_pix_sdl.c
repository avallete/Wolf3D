/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pix_sdl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 09:22:53 by avallete          #+#    #+#             */
/*   Updated: 2015/03/12 10:25:10 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_SDL.h>

void	draw_pix_sdl(SDL_Surface *surface, t_pixsdl *pix)
{
	int			place;
	Uint8		*pos;

	place = PLACE_IMG(pix->x, pix->y, surface);
	if (place < IMG_MAX(surface) && place >= 0)
	{
		if (pix->x >= 0 && pix->x <= surface->w)
		{
			SDL_LockSurface(surface);
			pos = surface->pixels + place;
			*pos = pix->color >> 16;
			*(pos + 1) = pix->color >> 8;
			*(pos + 2) = pix->color;
			SDL_UnlockSurface(surface);
		}
	}
}
