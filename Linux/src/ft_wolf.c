#include "ft_wolf.h"

void	init_ray(t_game *wolf, int x, t_ray *ray)
{
	int		camx;

	camx = (((2 * x) / WINX(wolf->sdl)) - 1);
	ray->x = CAM(wolf).x;
	ray->y = CAM(wolf).y;
	ray->dx = CAM(wolf).dx + PLAN(wolf).x * camx;
	ray->dy = CAM(wolf).dy + PLAN(wolf).y * camx;
	ray->px = (int)ray->x;
	ray->py = (int)ray->y;
	ray->dltx = sqrt(1 + (ray->dx * ray->dy) / (ray->dx * ray->dx));
	ray->dlty = sqrt(1 + (ray->dx * ray->dx) / (ray->dy * ray->dy));
	ray->dx < 0 ? (ray->incx = -1) : (ray->incx = 1);
	ray->dx < 0 ? (ray->sdx = (ray->x - ray->px) * ray->dltx) :\
	(ray->sdx = (ray->px + 1 - ray->x) * ray->dltx);
	ray->dy < 0 ? (ray->incy = -1) : (ray->incy = 1);
	ray->dy < 0 ? (ray->sdx = (ray->y - ray->py) * ray->dlty) :\
	(ray->sdx = (ray->py + 1 - ray->y) * ray->dlty);
}

void	increment_ray(t_ray *ray)
{
	if (ray->sdx < ray->sdy)
	{
		ray->sdx += ray->dltx;
		ray->px += ray->incx;
		ray->side = 0;
	}
	else
	{
		ray->sdy += ray->dlty;
		ray->py += ray->incy;
		ray->side = 1;
	}
}

void	trace_col(t_game *wolf, t_ray *ray, int x)
{
	double		persp;
	int		hight;
	t_pixsdl	start;
	t_pixsdl	end;

	ray->side == 0 ? (persp = abs((ray->px - ray->x) + ((1 - ray->incx) / 2) / ray->dx)) :\
	(persp = abs((ray->py - ray->y) + ((1 - ray->incy) / 2) / ray->dy));
	hight = (int)abs((WINY(wolf->sdl) / persp));
	start.x = x;
	start.y = (int)(-hight / 2 + (WINY(wolf->sdl)) / 2);
	ray->side == 1 ? (start.color = 0x5f8ea6) : (start.color = 0x78ff51e);
	end.x = x;
	end.y = (int)(hight / 2 + (WINY(wolf->sdl)) / 2);
	if (start.y < 0)
		start.y = 0;
	if (end.y >= (int)WINY(wolf->sdl))
		end.y = WINY(wolf->sdl) - 1;
	draw_line_sdl(WIN(wolf->sdl, screen), start, end);
}

void	print_wall(t_game *wolf)
{
	unsigned int	x;
	char		hit;
	t_pixsdl	pix;
	t_ray		ray;

	x = 0;
	SDL_LockSurface(WIN(wolf->sdl, screen));
	while (x < WINX(wolf->sdl))
	{
		hit = 0;
		init_ray(wolf, x, &ray);
		while (hit == 0)
		{
			increment_ray(&ray);
			pix = ft_getpix(MAPLVL(wolf), ray.px, ray.py);
			pix.color == 0 ? (hit = 1) : (hit = 0);
		}
		trace_col(wolf, &ray, x);
		x++;
	}
	SDL_UnlockSurface(WIN(wolf->sdl, screen));
}

void	draw_background(t_game *wolf)
{
	SDL_LockSurface(WIN(wolf->sdl, screen));
	SDL_FillRect(WIN(wolf->sdl, screen), &FLOOR(wolf), 0xff906200);
	SDL_FillRect(WIN(wolf->sdl, screen), &SKY(wolf), 0xff00b89e);
	SDL_UnlockSurface(WIN(wolf->sdl, screen));
}

void	move(t_game *wolf)
{
	t_pixsdl pix;
	if (PLAYER(wolf)->dep[0])
	{
		pix = ft_getpix(MAPLVL(wolf), PLAYER(wolf)->pos.x, PLAYER(wolf)->pos.y);
		if (pix.color > 0)
		{
		PLAYER(wolf)->pos.x += PLAYER(wolf)->cam.dx * 1;
		PLAYER(wolf)->cam.x += PLAYER(wolf)->cam.dx * 1;
		PLAYER(wolf)->pos.y += PLAYER(wolf)->cam.dy * 1;
		PLAYER(wolf)->cam.y += PLAYER(wolf)->cam.dy * 1;
		}
	}
}

void	play_level(t_game *wolf)
{
	wolf->player->dist = ((WINX(wolf->sdl) / 2) / tan(RAD(FOV / 2)));
	while ((!(wolf->sdl->key->echap)) && (!(wolf->inf->win)))
	{
		draw_background(wolf);
		print_wall(wolf);
		ft_bzero(wolf->player->dep, 4);
		ft_bzero(wolf->player->rot, 4);
		SDL_UpdateWindowSurface(WIN(wolf->sdl, win));
		ft_keyhook_sdl(wolf->sdl, wolf, ft_keyboard, ft_mouse);
		move(wolf);
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
			ft_launch_sdl(ft_wolf, 320, 200, 4);
		else
		{
			ft_putsterr("SDL Could not initialize\n");
			return (-1);
		}
	}
	return (0);
}
