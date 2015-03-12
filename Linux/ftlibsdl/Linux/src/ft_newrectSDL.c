#include "ft_SDL.h"

SDL_Rect	ft_newrectSDL(int x, int y, size_t width, size_t hight)
{
	SDL_Rect new;

	new.x = x;
	new.y = y;
	new.w = width;
	new.h = hight;
	return (new);
}
