#include "ft_wolf.h"

void	ft_keyboard(t_envsdl *sdl, SDL_Keysym k, void *data)
{
	t_game *wolf;

	wolf = data;
	if (wolf)
		data = data;
	if (k.sym == SDLK_ESCAPE)
		sdl->key->echap = 1;
	if (k.sym == SDLK_z || k.sym == SDLK_s)
		k.sym == SDLK_z ? (wolf->player->dep[0] = 1) \
		: (wolf->player->dep[1] = 1);
	if (k.sym == SDLK_q || k.sym == SDLK_d)
		k.sym == SDLK_q ? (wolf->player->dep[2] = 1) \
		: (wolf->player->dep[3] = 1);
	if (k.sym == SDLK_LEFT || k.sym == SDLK_RIGHT)
		k.sym == SDLK_LEFT ? (wolf->player->rot[1] = 1) \
		: (wolf->player->rot[2] = 1);
	ft_printf("key = %d\n", k);
}
