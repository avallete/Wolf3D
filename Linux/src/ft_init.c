#include "ft_wolf.h"

void	init_player(t_player *player)
{
	player->fov = RAD(66);
	player->pos.x = 15;
	player->pos.y = 15;
	player->dir.x = -1;
	player->dir.y = 0;
	player->plan.x = 0;
	player->plan.y = player->fov;
	player->map.x = 15;
	player->map.y = 15;
	player->map.color = 0xfabcdef;
	player->hight = WALLSIZE / 2;
	ft_bzero(player->dep, 4);
	ft_bzero(player->rot, 4);
}

int	init_level(t_map *level, t_inf *inf, t_envsdl *sdl)
{
	level->map = ft_loadbmp_sdl(sdl, inf->mappath);
	level->floor = ft_newrect_sdl(0, WINY(sdl) / 2, WINX(sdl), \
			WINY(sdl) / 2);
	level->sky = ft_newrect_sdl(0, 0, WINX(sdl), WINY(sdl) / 2);
	if (level->map)
		return (0);
	else
	{
		ft_putsterr("Map level can't be opened\n");
		return (-1);
	}
}

void	init_inf(t_inf *inf)
{
	inf->win = 0;
	inf->level = 0;
	inf->mappath = ft_strdup("res/levels/map0.bmp");
}

void	init_control_func(t_game *wolf)
{
	wolf->func[0] = ft_keyboard;
	wolf->func[1] = ft_mouse;
	wolf->func[2] = ft_controller;
}

