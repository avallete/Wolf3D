/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 16:31:10 by avallete          #+#    #+#             */
/*   Updated: 2015/03/26 17:13:14 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

static void	add_wall(t_game *e)
{
	double dir;
	t_pixsdl pix;

	dir = 2;
	ft_getpix(e->level->map, &pix,  PLRPOS(e).x + e->player->dir.x * dir, \
				PLRPOS(e).y + e->player->dir.y * dir);
	if (pix.color > 0xff000000)
	{
		pix.color = e->player->cubecolor;
		draw_pix_sdl(e->level->map, &pix);
	}
}

static void	remove_wall(t_game *e)
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

void	show_cubecolor(t_game *wolf)
{
	SDL_LockSurface(WIN(wolf->sdl, screen));
	SDL_FillRect(WIN(wolf->sdl, screen), &(wolf->player->cube), \
			wolf->player->cubecolor);
	SDL_UnlockSurface(WIN(wolf->sdl, screen));
	SDL_UpdateWindowSurface(WIN(wolf->sdl, win));
	SDL_Delay(30);
}

void	mod_cubecol(t_game *wolf, int r, int g, int b)
{
	Uint8 *colors = (Uint8*)&wolf->player->cubecolor;
	colors[0] += r;
	colors[1] += g;
	colors[2] += b;
	wolf->player->cubecolor <= 0xff000000 ? \
	(wolf->player->cubecolor = 0xff000001) : 0;
	show_cubecolor(wolf);
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
	if (k.sym == SDLK_DELETE)
		remove_wall(wolf);
	if (k.sym == SDLK_TAB)
		show_cubecolor(wolf);
	if (k.sym == SDLK_KP_1 || k.sym == SDLK_KP_3)
		k.sym == SDLK_1 ? mod_cubecol(wolf, -1, 0, 0) : mod_cubecol(wolf, 1, 0, 0);
	if (k.sym == SDLK_KP_4 || k.sym == SDLK_KP_6)
		k.sym == SDLK_1 ? mod_cubecol(wolf, 0, -1, 0) : mod_cubecol(wolf, 0, 1, 0);
	if (k.sym == SDLK_KP_7 || k.sym == SDLK_KP_9)
		k.sym == SDLK_1 ? mod_cubecol(wolf, 0, 0, -1) : mod_cubecol(wolf, 0, 0, 1);
}
