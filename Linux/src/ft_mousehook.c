#include "ft_wolf.h"

void	ft_mouse(t_envSDL *sdl, void *data)
{
	t_pixSDL mouse;
	t_game *wolf;

	wolf = data;
	if (wolf && sdl)
	{
		SDL_GetMouseState(&(mouse.x), &(mouse.y));
		draw_pixSDL(WIN(wolf->sdl, screen), &mouse);
		ft_printf("mouse event x, y = %, %d, %d\n", mouse.x, mouse.y);
	}
}
