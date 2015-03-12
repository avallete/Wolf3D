#include "ft_wolf.h"

void	ft_mouse(t_envsdl *sdl, void *data)
{
	t_pixsdl mouse;
	t_game *wolf;

	wolf = data;
	if (wolf && sdl)
	{
		SDL_GetMouseState(&(mouse.x), &(mouse.y));
		mouse.color = 0xfab98fa;
		draw_pix_sdl(WIN(wolf->sdl, screen), &mouse);
		ft_printf("mouse event x, y = %, %d, %d\n", mouse.x, mouse.y);
	}
}
