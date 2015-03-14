#include "ft_wolf.h"

void	draw_background(t_game *wolf)
{
	SDL_LockSurface(WIN(wolf->sdl, screen));
	SDL_FillRect(WIN(wolf->sdl, screen), &FLOOR(wolf), 0xff906200);
	SDL_FillRect(WIN(wolf->sdl, screen), &SKY(wolf), 0xff00b89e);
	SDL_UnlockSurface(WIN(wolf->sdl, screen));
}

void	inc_ray(t_game *e, t_ray *ray)
{
	ray->x += ray->xa;
	ray->y += ray->ya;
	ray->mapos = ft_getpix(MAPLVL(e), ray->x / WALLSIZE, ray->y / WALLSIZE);
}

void	init_ray(t_game *e, t_ray *ray, int x)
{
	ray->rot = RAD(e->player->pos.rot) + (RAD(x) - (FOV(e) / 2));
	ray->rot > 0.0000001 ? (ray->y = ((PLRPOS(e).y / WALLSIZE) * (WALLSIZE)) - 1) :\
	(ray->y = (PLRPOS(e).y / WALLSIZE) * (WALLSIZE));
	ray->x = (PLRPOS(e).x + (PLRPOS(e).y - ray->y)) / tan(ray->rot);
	ray->mapos = ft_getpix(MAPLVL(e), ray->x / WALLSIZE, ray->y / WALLSIZE);
	ray->xa = WALLSIZE / tan(ray->rot);
	ray->rot > 0.0000001 ? (ray->ya = WALLSIZE) :\
	(ray->ya = -WALLSIZE);
}

void	draw_it(t_game *e)
{
	 unsigned int	x;
	 t_ray			ray;

	 x = 0;
	 while (x < WX(e))
	 {
		 init_ray(e, &ray, x);
	//	 inc_ray(e, &ray);
	//	 while (ray.mapos.color != 0)
	//	 	inc_ray(e, &ray);
		 printf("raypos : %e:%e \nray wallpos: %d:%d\nray inc : %e:%e\n", ray.x, ray.y, ray.mapos.x, ray.mapos.y, ray.xa, ray.ya);
		 printf("player : %d:%d \nplayer wallpos: %d:%d\n", PLRPOS(e).x, PLRPOS(e).y, e->player->map.x, e->player->map.y);
		 x++;
	 }
}

void	play_level(t_game *e)
{
	while ((!(e->sdl->key->echap)) && (!(e->inf->win)))
	{
		e->player->dist = DIST(e);
		draw_background(e);
		draw_it(e);
		ft_bzero(e->player->dep, 4);
		ft_bzero(e->player->rot, 4);
		SDL_UpdateWindowSurface(WIN(e->sdl, win));
		ft_keyhook_sdl(e->sdl, e, ft_keyboard, ft_mouse);
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
			ft_launch_sdl(ft_wolf, 100, 90, 4);
		else
		{
			ft_putsterr("SDL Could not initialize\n");
			return (-1);
		}
	}
	return (0);
}
