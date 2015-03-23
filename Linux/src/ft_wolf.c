#include "ft_wolf.h"

void	draw_background(t_game *wolf)
{
	SDL_LockSurface(WIN(wolf->sdl, screen));
	SDL_FillRect(WIN(wolf->sdl, screen), &FLOOR(wolf), 0xff906200);
	SDL_FillRect(WIN(wolf->sdl, screen), &SKY(wolf), 0xff00b89e);
	SDL_UnlockSurface(WIN(wolf->sdl, screen));
}

void	draw_it(t_game *e)
{
	unsigned int	x;
	t_ray			h;

	x = 0;
	h.mapos.x = 0;
	h.mapos.y = 0;
	h.mapos.color = 0;
	while (x < WX(e))
	{
		init_ray(e, x, &h);
		if ((h.mapos.x >= 0 && h.mapos.x < LVX(e)) && h.mapos.y >= 0 && h.mapos.y < LVY(e))
		{
			while (!h.stop && (h.mapos.x >= 0 && h.mapos.x <= LVX(e)) && h.mapos.y >= 0 && h.mapos.y <= LVY(e))
				inc_ray(e, &h);
			draw_wall(e, &h, x);
		}
		x++;
	}
}

void	move(t_game *e)
{
	t_pixsdl	testy;
	t_nc		oldir;
	t_nc		oldplan;
	double		dirdep;
	double		dirrot;

	if (e->player->dep[0])
	{
		dirdep = 0.1 * e->player->dep[0];
		ft_getpix(e->level->map, &testy, PLRPOS(e).x + e->player->dir.x * dirdep, PLRPOS(e).y + e->player->dir.y * dirdep);
		if (testy.color == 0xffffff)
		{
			e->player->pos.y += e->player->dir.y * dirdep;
			e->player->pos.x += e->player->dir.x * dirdep;
		}
	}
	if (e->player->rot[0])
	{
		dirrot = 0.15 * e->player->rot[0];
		oldir.x = e->player->dir.x;
		oldplan.x = e->player->plan.x;
		e->player->dir.x = e->player->dir.x * cos(dirrot) - e->player->dir.y * sin(dirrot);
		e->player->dir.y = oldir.x * sin(dirrot) + e->player->dir.y * cos(dirrot);
		e->player->plan.x = e->player->plan.x * cos(dirrot) - e->player->plan.y * sin(dirrot);
		e->player->plan.y = oldplan.x * sin(dirrot) + e->player->plan.y * cos(dirrot);
	}
}

void	init_joystick(t_game *e)
{
	if (SDL_NumJoysticks() > 0)
	{
		e->joy = SDL_JoystickOpen(0);
		if (e->joy)
		{
			ft_printf("%s detected.\n", SDL_JoystickName(e->joy));
			SDL_JoystickEventState(SDL_ENABLE);
		}
	}
}

void	play_level(t_game *e)
{
	while ((!(e->sdl->key->echap)) && (!(e->inf->win)))
	{
		e->player->dist = DIST(e);
		draw_background(e);
		draw_it(e);
		ft_bzero(e->player->dep, (sizeof(int)) * 4);
		ft_bzero(e->player->rot, (sizeof(int)) * 4);
		SDL_UpdateWindowSurface(WIN(e->sdl, win));
		ft_keyhook_sdl(e->sdl, e, e->func);
		move(e);
	}
}

void	play_it(t_game *game)
{
	while (!(game->sdl->key->echap))
	{
		init_joystick(game);
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
	{
		wolf.player = &player;
		wolf.inf = &inf;
		wolf.level = &map;
		init_control_func(&wolf);
		init_inf(wolf.inf);
		if (init_level(wolf.level, wolf.inf, sdl) > -1)
		{
			init_player(wolf.player);
			wolf.sdl = sdl;
			play_it(&wolf);
		}
	}
	ft_free_sdl(sdl);
}

int	main(int argc, char **argv)
{
	if (argc && argv)
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) > -1)
			ft_launch_sdl(ft_wolf, 500, 500, 4);
		else
		{
			ft_putsterr("SDL Could not initialize\n");
			return (-1);
		}
	}
	return (0);
}
