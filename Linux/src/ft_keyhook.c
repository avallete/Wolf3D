#include "ft_wolf.h"

void	ft_keyboard(t_envsdl *sdl, void *data)
{
	t_game *wolf;
	SDL_Keysym k;

	k = EVNT_KEY(sdl);
	wolf = data;
	if (wolf)
		(void)data;
	if (k.sym == SDLK_ESCAPE)
		sdl->key->echap = 1;
	if (k.sym == SDLK_w || k.sym == SDLK_s)
		k.sym == SDLK_w ? (wolf->player->dep[0] = 1) \
		: (wolf->player->dep[0] = -1);
	if (k.sym == SDLK_a || k.sym == SDLK_d)
		k.sym == SDLK_a ? (wolf->player->dep[1] = 1) \
		: (wolf->player->dep[1] = -1);
	if (k.sym == SDLK_LEFT || k.sym == SDLK_RIGHT)
		k.sym == SDLK_LEFT ? (wolf->player->rot[0] = 1) \
		: (wolf->player->rot[0] = -1);
}
