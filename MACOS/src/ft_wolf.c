/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 12:06:04 by avallete          #+#    #+#             */
/*   Updated: 2015/04/04 13:04:23 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

static void	play_level(t_game *e)
{
	while ((!(e->sdl->key->echap)) && (!(e->inf->win)))
	{
		e->player->dist = DIST(e);
		draw_background(e);
		draw_it(e);
		SDL_UpdateWindowSurface(WIN(e->sdl, win));
		ft_keyhook_sdl(e->sdl, e, e->func);
		move(e);
	}
}

static void	play_it(t_game *e)
{
	while (!(e->sdl->key->echap))
	{
		if (init_level(e->level, e->inf, e->sdl) > -1)
		{
			init_player(e->player, e->level);
			play_level(e);
			e->inf->win = 0;
		}
	}
}

void		ft_wolf(t_envsdl *sdl)
{
	t_game		wolf;
	t_inf		inf;
	t_player	player;
	t_map		map;

	if (sdl)
	{
		wolf.player = &player;
		wolf.inf = &inf;
		map.map = NULL;
		wolf.level = &map;
		init_control_func(&wolf);
		init_inf(wolf.inf);
		if (init_level(wolf.level, wolf.inf, sdl) > -1)
		{
			init_player(wolf.player, wolf.level);
			ft_bzero(wolf.player->dep, sizeof(int) * 4);
			ft_bzero(wolf.player->rot, sizeof(int) * 4);
			wolf.sdl = sdl;
			play_it(&wolf);
			ft_free_wolf(&wolf);
		}
	}
}

int			main(int argc, char **argv)
{
	if (argc && argv)
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) > -1)
			ft_launch_sdl(ft_wolf, 1920, 1080, 4);
		else
		{
			ft_putsterr("SDL Could not initialize\n");
			return (-1);
		}
	}
	return (0);
}
