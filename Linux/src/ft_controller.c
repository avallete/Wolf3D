#include "ft_wolf.h"

static void	ft_axis(t_game *e)
{
	Uint8 state;

	state = SDL_JoystickGetHat(e->joy, SDL_HAT_UP);
	ft_printf("%d\n", state);
}

void		ft_controller(t_envsdl *sdl, void *data)
{
	t_game *e;

	ft_printf("wazaa\n");
	e = (t_game*)data;
	if (EVNT_T(sdl) == SDL_JOYAXISMOTION)
		ft_axis(e);
}
