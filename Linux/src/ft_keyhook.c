/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 16:31:10 by avallete          #+#    #+#             */
/*   Updated: 2015/03/27 16:38:12 by avallete         ###   ########.fr       */
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
	Uint8 *colors;

	colors = (Uint8*)&wolf->player->cubecolor;
	colors[0] + r < 255 || colors[0] + r > 20 ? (colors[0] += r) : 0;
	colors[1] + g < 255 || colors[1] + g > 20 ? (colors[1] += g) : 0;
	colors[2] + b < 255 || colors[2] + b > 20 ? (colors[2] += b) : 0;
	colors[3] = 0;
	show_cubecolor(wolf);
}

void	create_map(t_game *e)
{
	size_t			size[2];
	t_nc			propor;
	t_pixsdl		pix;

	SDL_LockSurface(WIN(e->sdl, screen));
	pix.y = 0;
	propor.x = CX(e) / e->level->map->w;
	propor.y = CY(e) / e->level->map->h;
	size[0] = (CX(e) /  propor.x) / 2;
	size[1] = (CY(e) / propor.y) / 2;
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
	e->level->mapview = ft_newrect_sdl(PLRMPO(e).x * size[0],\
	PLRMPO(e).y * size[1], size[0], size[1]);
	SDL_FillRect(WIN(e->sdl, screen), &(e->level->mapview), \
	PLRMPO(e).color);
	SDL_UnlockSurface(WIN(e->sdl, screen));
	SDL_UpdateWindowSurface(WIN(e->sdl, win));
	SDL_Delay(300);
}

int		test_filexist(char *path)
{
	int fd;

	fd = 0;
	if ((fd = open(path, O_RDONLY)) >= 0)
	{
		close(fd);
		return (1);
	}
	return (0);
}

int		test_scrfile(t_game *e)
{
	char *path;
	char *itoa;
	char *tmp;
	int ret;

	itoa = ft_itoa(e->inf->nb);
	tmp = ft_strjoin(itoa, ".bmp");
	path = ft_strjoin(e->inf->scrspath, tmp);
	ret = test_filexist(path);
	free(itoa);
	free(tmp);
	free(path);
	return (ret);
}

void	save_map(t_game *e)
{
	char *path;
	char *itoa;
	char *tmp;

	while (test_scrfile(e))
		e->inf->nb++;
	itoa = ft_itoa(e->inf->nb);
	tmp = ft_strjoin(itoa, ".bmp");
	path = ft_strjoin(e->inf->scrspath, tmp);
	if (SDL_SaveBMP(e->level->map, path) >= 0)
		ft_printf("Save screenshot : %s\n", path);
	else
		ft_printf("Couldn't save screenshot : %s\n", path);
	free(itoa);
	free(tmp);
	free(path);
	SDL_Delay(500);
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
		k.sym == SDLK_1 ? mod_cubecol(wolf, -1, 0, 0) : mod_cubecol(wolf, 1, 0, 0);
	if (k.sym == SDLK_KP_4 || k.sym == SDLK_KP_6)
		k.sym == SDLK_1 ? mod_cubecol(wolf, 0, -1, 0) : mod_cubecol(wolf, 0, 1, 0);
	if (k.sym == SDLK_KP_7 || k.sym == SDLK_KP_9)
		k.sym == SDLK_1 ? mod_cubecol(wolf, 0, 0, -1) : mod_cubecol(wolf, 0, 0, 1);
	if (k.sym == SDLK_p)
		create_map(wolf);
	if (EVNT_T(sdl) == SDL_KEYDOWN && k.sym == SDLK_y)
		save_map(wolf);
}
