/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 16:31:10 by avallete          #+#    #+#             */
/*   Updated: 2015/04/04 13:08:14 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

static void	draw_map(t_game *e, t_pixsdl pix, size_t *size)
{
	while (pix.y < e->level->map->h)
	{
		pix.x = 0;
		while (pix.x < e->level->map->w)
		{
			ft_getpix(e->level->map, &pix, pix.x, pix.y);
			e->level->mapview = ft_newrect_sdl(pix.x * size[0], pix.y * size[1]\
					, size[0], size[1]);
			SDL_FillRect(WIN(e->sdl, screen), &(e->level->mapview), \
					pix.color);
			pix.x++;
		}
		pix.y++;
	}
}

static void	create_map(t_game *e)
{
	size_t			size[2];
	t_nc			propor;
	t_pixsdl		pix;

	SDL_LockSurface(WIN(e->sdl, screen));
	pix.y = 0;
	propor.x = CX(e) / e->level->map->w;
	propor.y = CY(e) / e->level->map->h;
	size[0] = (CX(e) / propor.x) / 2;
	size[1] = (CY(e) / propor.y) / 2;
	draw_map(e, pix, size);
	e->level->mapview = ft_newrect_sdl(PLRMPO(e).x * size[0],\
			PLRMPO(e).y * size[1], size[0], size[1]);
	SDL_FillRect(WIN(e->sdl, screen), &(e->level->mapview), \
			PLRMPO(e).color);
	SDL_UnlockSurface(WIN(e->sdl, screen));
	SDL_UpdateWindowSurface(WIN(e->sdl, win));
	SDL_Delay(300);
}

void		ft_keyboard(t_envsdl *sdl, void *data)
{
	t_game		*wolf;
	SDL_Keysym	k;
	int			mode;

	k = EVNT_KEY(sdl);
	wolf = data;
	(EVNT_T(sdl) == SDL_KEYDOWN) ? (mode = 1)\
	: (mode = 0);
	if (k.sym == SDLK_ESCAPE)
		sdl->key->echap = mode;
	if (MOVUP || MOVDO)
		MOVUP ? (wolf->player->dep[0] = mode) \
		: (wolf->player->dep[0] = -mode);
	if (k.sym == SDLK_a || k.sym == SDLK_d)
		k.sym == SDLK_a ? (wolf->player->dep[1] = -mode) \
		: (wolf->player->dep[1] = mode);
	if (k.sym == SDLK_LEFT || k.sym == SDLK_RIGHT)
		k.sym == SDLK_LEFT ? (wolf->player->rot[0] = mode) \
		: (wolf->player->rot[0] = -mode);
	kcheck_wall_action(wolf, sdl, k);
	if (k.sym == SDLK_p)
		create_map(wolf);
	if (EVNT_T(sdl) == SDL_KEYDOWN && k.sym == SDLK_y)
		save_map(wolf);
	ft_check_level(sdl, wolf, k);
}
