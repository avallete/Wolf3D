/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 12:58:03 by avallete          #+#    #+#             */
/*   Updated: 2015/04/04 13:12:11 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WOLF_H
# define FT_WOLF_H
# define LVX(e) e->level->map->w
# define LVY(e) e->level->map->h
# define WX(e) WINX(e->sdl)
# define WY(e) WINY(e->sdl)
# define CX(e) WINX(e->sdl) / 2
# define CY(e) WINY(e->sdl) / 2
# define WALL 0
# define WALLSIZE 64
# define SPACE 0xffffffff
# define RAD(x)	(x * 0.017453292519943)
# define PLAYER(e)	e->player
# define PLRPOS(e)	e->player->pos
# define PLRMPO(e)	e->player->map
# define SKY(e)		e->level->sky
# define RP(e)		e->pos
# define RMP(e)		e->mapos
# define RD(e)		e->dir
# define RSD(e)		e->sd
# define RDT(e)		e->dlt
# define MAPLVL(e)	e->level->map
# define FLOOR(e) 	e->level->floor
# define DIST(e) ((WX(e) / (tan(RAD(e->player->fov / 2) * RAD(M_PI / 180)))))
# define FOV(e)		e->player->fov
# define MOVUP		(k.sym == SDLK_w || k.sym == SDLK_UP)
# define MOVDO		(k.sym == SDLK_s || k.sym == SDLK_DOWN)
# include "ft_sdl.h"
# include <math.h>
# include <fcntl.h>

typedef	struct		s_wall
{
	int				x;
	int				y;
	int				size;
}					t_wall;

typedef	struct		s_nc
{
	double			x;
	double			y;
}					t_nc;

typedef	struct		s_vec
{
	double			x;
	double			y;
	double			rot;
}					t_vec;

typedef	struct		s_ray
{
	t_nc			pos;
	t_nc			dir;
	t_pixsdl		mapos;
	t_nc			sd;
	t_nc			dlt;
	double			dist;
	int				incx;
	int				incy;
	char			side;
	char			stop;
}					t_ray;

typedef	struct		s_map
{
	SDL_Surface		*map;
	SDL_Rect		floor;
	SDL_Rect		sky;
	SDL_Rect		mapview;
}					t_map;

typedef	struct		s_player
{
	t_nc			pos;
	t_nc			dir;
	t_nc			plan;
	t_nc			cam;
	t_pixsdl		map;
	double			fov;
	double			dist;
	int				hight;
	int				dep[4];
	int				rot[4];
	char			col;
	Uint32			cubecolor;
	SDL_Rect		cube;
}					t_player;

typedef	struct		s_inf
{
	int				win;
	int				level;
	char			*mappath;
	char			*scrspath;
	int				nb;
}					t_inf;

typedef	struct		s_game
{
	t_map			*level;
	t_player		*player;
	t_inf			*inf;
	t_envsdl		*sdl;
	t_controlf		func[6];
	SDL_Joystick	*joy;
}					t_game;

/*
** Init structures
*/
void				init_inf(t_inf *inf);
int					init_level(t_map *level, t_inf *inf, t_envsdl *sdl);
void				init_player(t_player *player, t_map *level);
void				init_control_func(t_game *wolf);
void				ft_free_wolf(t_game *e);

/*
** Map functions
*/
void		define_color(t_game *e, t_ray *r, Uint32 *color, char mode);

/*
** Event functions
*/
void				ft_mouse(t_envsdl *sdl, void *data);
void				ft_keyboard(t_envsdl *sdl, void *data);
void				define_color(t_game *e, t_ray *r, Uint32\
					*color, char mode);
void				kcheck_wall_action(t_game *wolf, t_envsdl \
					*sdl, SDL_Keysym k);

/*
** Ray and wall drawing functions
*/
void				init_ray(t_game *e, int x, t_ray *r);
void				inc_ray(t_game *e, t_ray *r);
void				draw_wall(t_game *e, t_ray *r, int x);
void				draw_background(t_game *wolf);
void				draw_it(t_game *e);

/*
** Player actions
*/
void				move(t_game *e);
void				save_map(t_game *e);
void				change_level(t_game *e, int mode);
void				ft_check_level(t_envsdl *sdl, t_game *wolf, SDL_Keysym k);
void				sdl_surfreesec(SDL_Surface *src);
#endif
