#include <ft_SDL.h>

void	draw_pixSDL(SDL_Surface *surface, t_pixSDL *pix)
{
	int		place;
	Uint8		*pos;

	place = PLACE_IMG(pix->x, pix->y, surface);
	if (place < IMG_MAX(surface) && place >= 0)
	{
		if (pix->x >= 0 && pix->x <= surface->w)
		{
			SDL_LockSurface(surface);
			pos = surface->pixels + place;
			*pos = pix->color >> 16;
			*(pos+1) = pix->color >> 8;
			*(pos+2) = pix->color;
			SDL_UnlockSurface(surface);
		}
	}
}
