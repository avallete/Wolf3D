/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 09:15:20 by avallete          #+#    #+#             */
/*   Updated: 2015/03/15 14:34:45 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int		ft_getpix(SDL_Surface *img, t_pixsdl *pix, int x, int y)
{
	Uint8		*p;

	if (x > img->w || x < 0 || y > img->h || y < 0)
		return (0);
	pix->x = x;
	pix->y = y;
	p = img->pixels + PLACE_IMG(pix->x, pix->y, img);
	if (img->format->BytesPerPixel == 1)
		pix->color = *p;
	else if (img->format->BytesPerPixel == 2)
		pix->color = *(Uint16*)p;
	else if (img->format->BytesPerPixel == 3)
		SDL_BYTEORDER == SDL_BIG_ENDIAN ? (pix->color = ((p[0] << 16) | \
		(p[1] << 8) | p[2])) : (pix->color = (p[0] | (p[1] << 8) | \
		(p[2] << 16)));
	else if (img->format->BytesPerPixel == 4)
		pix->color = *(Uint32*)p;
	else
		return (0);
	return (1);
}
