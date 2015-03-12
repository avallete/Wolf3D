#include "ft_SDL.h"

void	ft_freeSDL(t_envSDL *sdl)
{
	if (WIN(sdl, screen))
		SDL_FreeSurface(WIN(sdl, screen));
	if (WIN(sdl, hwscreen))
		SDL_FreeSurface(WIN(sdl, hwscreen));
}
