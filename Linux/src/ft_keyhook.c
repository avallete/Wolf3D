#include "ft_wolf.h"

void	add_wall(t_game *e)
{
	double dir;
	t_pixsdl pix;

	dir = 2;
	ft_getpix(e->level->map, &pix,  PLRPOS(e).x + e->player->dir.x * dir, \
				PLRPOS(e).y + e->player->dir.y * dir);
	if (pix.color > 0xff000000)
	{
		pix.color = 0xf0ff0ff;
		draw_pix_sdl(e->level->map, &pix);
	}
}

void	remove_wall(t_game *e)
{
	double dir;
	t_pixsdl pix;

	dir = 2;
	ft_getpix(e->level->map, &pix,  PLRPOS(e).x + e->player->dir.x * dir, \
				PLRPOS(e).y + e->player->dir.y * dir);
	if (pix.color > 0xff000000)
	{
		pix.color = SPACE;
		draw_pix_sdl(e->level->map, &pix);
	}
}

void	ft_keyboard(t_envsdl *sdl, void *data)
{
	t_game *wolf;
	SDL_Keysym k;
	int mode;

	k = EVNT_KEY(sdl);
	wolf = data;
	if (wolf)
		(void)data;
	(EVNT_T(sdl) == SDL_KEYDOWN) ? (mode = 1) : \
				  (mode = 0);
	if (k.sym == SDLK_ESCAPE)
		sdl->key->echap = mode;
	if (k.sym == SDLK_w || k.sym == SDLK_s)
		k.sym == SDLK_w ? (wolf->player->dep[0] = mode) \
		: (wolf->player->dep[0] = -mode);
	if (k.sym == SDLK_a || k.sym == SDLK_d)
		k.sym == SDLK_a ? (wolf->player->dep[1] = -mode) \
		: (wolf->player->dep[1] = mode);
	if (k.sym == SDLK_LEFT || k.sym == SDLK_RIGHT)
		k.sym == SDLK_LEFT ? (wolf->player->rot[0] = mode) \
		: (wolf->player->rot[0] = -mode);
	if (k.sym == SDLK_SPACE)
		add_wall(wolf);
	if (k.sym == SDLK_DELETE)
		remove_wall(wolf);
}
