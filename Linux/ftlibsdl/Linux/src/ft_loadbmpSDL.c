#include "ft_SDL.h"

SDL_Surface	*ft_loadbmpSDL(t_envSDL *env, const char *path)
{
	SDL_Surface *imgloaded;
	SDL_Surface *optimize;

	imgloaded = NULL;
	optimize = NULL;
	if (!(imgloaded = SDL_LoadBMP(path)))
		ft_putsterr("Error Loading img\n");
	if (!(optimize = SDL_ConvertSurface(imgloaded, \
				WIN(env, screen)->format, 0)))
		ft_putsterr("Error Optimize\n");
		
	if (imgloaded)
		SDL_FreeSurface(imgloaded);
	return (optimize);
}
