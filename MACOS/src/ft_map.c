/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 12:11:22 by avallete          #+#    #+#             */
/*   Updated: 2015/04/01 12:32:48 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

static void	add_wall(t_game *e)
{
	double		dir;
	t_pixsdl	pix;

	dir = 2;
	ft_getpix(e->level->map, &pix, PLRPOS(e).x + e->player->dir.x * dir, \
			PLRPOS(e).y + e->player->dir.y * dir);
	if (pix.color > 0xff000000)
	{
		pix.color = e->player->cubecolor;
		draw_pix_sdl(e->level->map, &pix);
	}
}

static void	remove_wall(t_game *e)
{
	double		dir;
	t_pixsdl	pix;

	dir = 2;
	ft_getpix(e->level->map, &pix, PLRPOS(e).x + e->player->dir.x * dir, \
			PLRPOS(e).y + e->player->dir.y * dir);
	if (pix.color > 0xff000000)
	{
		pix.color = SPACE;
		draw_pix_sdl(e->level->map, &pix);
	}
}

static void	show_cubecolor(t_game *wolf)
{
	SDL_LockSurface(WIN(wolf->sdl, screen));
	SDL_FillRect(WIN(wolf->sdl, screen), &(wolf->player->cube), \
			wolf->player->cubecolor);
	SDL_UnlockSurface(WIN(wolf->sdl, screen));
	SDL_UpdateWindowSurface(WIN(wolf->sdl, win));
	SDL_Delay(30);
}

static void	mod_cubecol(t_game *wolf, int r, int g, int b)
{
	Uint8 *colors;

	colors = (Uint8*)&wolf->player->cubecolor;
	colors[0] + r < 255 || colors[0] + r > 20 ? (colors[0] += r) : 0;
	colors[1] + g < 255 || colors[1] + g > 20 ? (colors[1] += g) : 0;
	colors[2] + b < 255 || colors[2] + b > 20 ? (colors[2] += b) : 0;
	colors[3] = 0;
	show_cubecolor(wolf);
}

void		kcheck_wall_action(t_game *wolf, t_envsdl *sdl, SDL_Keysym k)
{
	if (k.sym == SDLK_c && EVNT_T(sdl) == SDL_KEYDOWN)
		wolf->player->col = !(wolf->player->col);
	if (k.sym == SDLK_SPACE)
		add_wall(wolf);
	if (k.sym == SDLK_DELETE)
		remove_wall(wolf);
	if (k.sym == SDLK_DELETE)
		remove_wall(wolf);
	if (k.sym == SDLK_TAB)
		show_cubecolor(wolf);
	if (k.sym == SDLK_KP_1 || k.sym == SDLK_KP_3)
		k.sym == SDLK_1 ? mod_cubecol(wolf, -1, 0, 0) :\
		mod_cubecol(wolf, 1, 0, 0);
	if (k.sym == SDLK_KP_4 || k.sym == SDLK_KP_6)
		k.sym == SDLK_1 ? mod_cubecol(wolf, 0, -1, 0) :\
		mod_cubecol(wolf, 0, 1, 0);
	if (k.sym == SDLK_KP_7 || k.sym == SDLK_KP_9)
		k.sym == SDLK_1 ? mod_cubecol(wolf, 0, 0, -1) :\
		mod_cubecol(wolf, 0, 0, 1);
}
