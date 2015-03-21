#include "ft_wolf.h"

void	draw_background(t_game *wolf)
{
	SDL_LockSurface(WIN(wolf->sdl, screen));
	SDL_FillRect(WIN(wolf->sdl, screen), &FLOOR(wolf), 0xff906200);
	SDL_FillRect(WIN(wolf->sdl, screen), &SKY(wolf), 0xff00b89e);
	SDL_UnlockSurface(WIN(wolf->sdl, screen));
}

void	draw_wall(t_game *e, t_ray *r, int x)
{
	t_pixsdl b;
	t_pixsdl end;
	int		wallh;

	if (r->side == 0)
		r->dist = fabs((RMP(r).x - RP(r).x + (1 - r->incx) / 2) / RD(r).x);
	else
		r->dist = fabs((RMP(r).y - RP(r).y + (1 - r->incy) / 2) / RD(r).y);
	wallh = abs(((int)(WY(e) / r->dist)));
	b.x = x;
	b.y = (-wallh / 2) + (WY(e) / 2);
	if (b.y < 0)
		b.y = 0;
	end.x = x;
	end.y = wallh / 2 + WY(e) / 2;
	if (end.y >= (int)WY(e))
		end.y = (int)WY(e) - 1;
	if (r->side == 1)
		b.color = r->mapos.color;
	else
		b.color = r->mapos.color / 1.5;
	draw_line_sdl(WIN(e->sdl, screen), b, end);
}

void	inc_ray(t_game *e, t_ray *r)
{
	t_pixsdl test;
	ft_getpix(e->level->map, &test, r->mapos.x, r->mapos.y);
	if (test.color != 0xffffff)
		r->stop = 1;
	else
	{
		if (RSD(r).x < RSD(r).y)
		{
			RSD(r).x += RDT(r).x;
			RMP(r).x += r->incx;
			r->side = 0;
		}
		else
		{
			RSD(r).y += RDT(r).y;
			RMP(r).y += r->incy;
			r->side = 1;
		}
		ft_getpix(e->level->map, &test, r->mapos.x, r->mapos.y);
		if (test.color != 0xffffff)
		{
			r->stop = 1;
			r->mapos.color = test.color;
		}
	}
}

void	init_ray(t_game *e, int x, t_ray *r)
{
	r->incx = 1;
	r->incy = 1;
	PLAYER(e)->cam.x = (2 * x) / ((double)(WX(e))) - 1;
	r->pos.x = PLAYER(e)->pos.x;
	r->pos.y = PLAYER(e)->pos.y;
	r->dir.x = PLAYER(e)->dir.x + PLAYER(e)->plan.x * PLAYER(e)->cam.x;
	r->dir.y = PLAYER(e)->dir.y + PLAYER(e)->plan.y * PLAYER(e)->cam.x;
	r->mapos.x = (int)r->pos.x;
	r->mapos.y = (int)r->pos.y;
	r->dlt.y = sqrt(1.0 + (RD(r).x * RD(r).x) / (RD(r).y * RD(r).y));
	r->dlt.x = sqrt(1.0 + (RD(r).y * RD(r).y) / (RD(r).x * RD(r).x));
	RSD(r).x = (RMP(r).x + (1.0 - RP(r).x)) * RDT(r).x;
	RSD(r).y = (RMP(r).y + (1.0 - RP(r).y)) * RDT(r).y;
	RD(r).x < 0 ? (r->incx = -1), \
				 (RSD(r).x = (RP(r).x - RMP(r).x) * RDT(r).x) : 0;
	RD(r).y < 0 ? (r->incy = -1), \
				 (RSD(r).y = (RP(r).y - RMP(r).y) * RDT(r).y) : 0;
	r->stop = 0;
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
			while (!h.stop && (h.mapos.x >= 0 && h.mapos.x < LVX(e)) && h.mapos.y >= 0 && h.mapos.y < LVY(e))
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
		ft_keyhook_sdl(e->sdl, e, ft_keyboard, ft_mouse);
		move(e);
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
			ft_launch_sdl(ft_wolf, 500, 500, 4);
		else
		{
			ft_putsterr("SDL Could not initialize\n");
			return (-1);
		}
	}
	return (0);
}
