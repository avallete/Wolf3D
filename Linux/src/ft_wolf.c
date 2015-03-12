#include "ft_wolf.h"

int	test_pix(t_game *wolf)
{
	t_pixsdl pix;

	pix = ft_getpix(wolf->level->map, RAY(wolf).cpx, RAY(wolf).cpy);
	ft_printf("color = %lx\n", pix.color);
	if (pix.color == 0)
		return (1);
	return (0);
}

void	play_level(t_game *wolf)
{
	const Uint8 *kb;

	kb = SDL_GetKeyboardState(NULL);
	SDL_FillRect(WIN(wolf->sdl, screen), &FLOOR(wolf), 0xff906200);
	SDL_FillRect(WIN(wolf->sdl, screen), &SKY(wolf), 0xff00b89e);
	while ((!(wolf->sdl->key->echap)) && (!(wolf->inf->win)))
	{
		ft_printf("dep: %d.%d.%d.%d\n", wolf->player->dep[0], \
		wolf->player->dep[1], wolf->player->dep[2], wolf->player->dep[3]);
		ft_bzero(wolf->player->dep, 4);
		SDL_UpdateWindowSurface(WIN(wolf->sdl, win));
		ft_keyhook_sdl(wolf->sdl, wolf, ft_keyboard, ft_mouse);
		wolf->player->dep[0] = kb[SDL_SCANCODE_UP];
		wolf->player->dep[1] = kb[SDL_SCANCODE_DOWN];
		wolf->player->dep[2] = kb[SDL_SCANCODE_LEFT];
		wolf->player->dep[3] = kb[SDL_SCANCODE_RIGHT];
	}
}

void	play_it(t_game *game)
{
	while (!(game->sdl->key->echap))
	{
		play_level(game);
	}
}

void	ft_wolf(t_envsdl *sdl)
{
	t_game		wolf;
	t_inf		inf;
	t_player	player;
	t_map		map;

	if (sdl)
		wolf.player = &player;
	wolf.inf = &inf;
	wolf.level = &map;
	init_inf(wolf.inf);
	if (init_level(wolf.level, wolf.inf, sdl) > -1)
	{
		init_player(wolf.player);
		wolf.sdl = sdl;
		play_it(&wolf);
	}
	ft_free_sdl(sdl);
}

int	main(int argc, char **argv)
{
	if (argc && argv)
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) > -1)
			ft_launch_sdl(ft_wolf, 320, 200, 4);
		else
		{
			ft_putsterr("SDL Could not initialize\n");
			return (-1);
		}
	}
	return (0);
}
