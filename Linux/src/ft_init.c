/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 16:30:48 by avallete          #+#    #+#             */
/*   Updated: 2015/03/27 16:30:56 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

void	init_player(t_player *player)
{
	player->fov = RAD(60);
	player->pos.x = 15;
	player->pos.y = 15;
	player->dir.x = -1;
	player->dir.y = 0;
	player->plan.x = 0;
	player->plan.y = player->fov;
	player->map.x = (int)player->pos.x;
	player->map.y = (int)player->pos.y;
	player->map.color = 0xE74C3C;
	player->hight = WALLSIZE / 2;
	player->cubecolor = 0xf1f2f3f4;
	ft_bzero(player->dep, 4);
	ft_bzero(player->rot, 4);
	player->cube = ft_newrect_sdl(0, 0, 30, 30);
	player->col = 0;
}

int	init_level(t_map *level, t_inf *inf, t_envsdl *sdl)
{
	level->map = NULL;
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
	inf->scrspath = ft_strdup("res/scr/");
	inf->nb = 0;
}

void	init_control_func(t_game *wolf)
{
	wolf->func[0] = ft_keyboard;
	wolf->func[1] = NULL;
	wolf->func[2] = NULL;
	wolf->func[3] = NULL;
	wolf->func[4] = NULL;
	wolf->func[5] = NULL;
	wolf->joy = NULL;
}

