/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 16:30:48 by avallete          #+#    #+#             */
/*   Updated: 2015/04/04 13:12:13 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

void	init_player(t_player *player, t_map *level)
{
	t_pixsdl	init;

	init.x = 15;
	init.y = 15;
	init.color = SPACE;
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
	draw_pix_sdl(level->map, &init);
}

int		init_level(t_map *level, t_inf *inf, t_envsdl *sdl)
{
	char *path;
	char *itoa;
	char *imgname;

	sdl_surfreesec(level->map);
	level->map = NULL;
	itoa = ft_itoa(inf->nb);
	imgname = ft_strjoin(itoa, ".bmp");
	ft_secfree(itoa);
	path = ft_strjoin(inf->mappath, imgname);
	ft_secfree(imgname);
	level->map = ft_loadbmp_sdl(sdl, path);
	ft_secfree(path);
	level->floor = ft_newrect_sdl(0, WINY(sdl) / 2, WINX(sdl), \
			WINY(sdl) / 2);
	level->sky = ft_newrect_sdl(0, 0, WINX(sdl), WINY(sdl) / 2);
	if (level->map)
		return (0);
	else
	{
		ft_putsterr("Map level can't be opened\n");
		inf->nb = 0;
		return (-1);
	}
}

void	init_inf(t_inf *inf)
{
	inf->win = 0;
	inf->level = 0;
	inf->mappath = ft_strdup("res/levels/map");
	inf->scrspath = ft_strdup("res/scr/screen");
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
