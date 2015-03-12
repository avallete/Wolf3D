#include "ft_SDL.h"

t_pixSDL	ft_getpix(SDL_Surface *img, int x, int y)
{
	t_pixSDL pix;
	Uint8 *p;

	pix.x = x;
	pix.y = y;
	p = img->pixels + PLACE_IMG(pix.x, pix.y, img);
	if (img->format->BytesPerPixel == 1)
		pix.color = *p;
	else if (img->format->BytesPerPixel == 2)
		pix.color = *(Uint16*)p;
	else if (img->format->BytesPerPixel == 3)
		SDL_BYTEORDER == SDL_BIG_ENDIAN ? (pix.color = ((p[0] << 16) | \
		(p[1] << 8) | p[2])) : (pix.color = (p[0] | (p[1] << 8) | \
		(p[2] << 16)));
	else if (img->format->BytesPerPixel == 4)
		pix.color = *p;
	else
		pix.color = 0;
	return (pix);
}
