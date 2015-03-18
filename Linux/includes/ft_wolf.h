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
# define SPACE 0xff
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
# include <stdio.h>
# include "ft_sdl.h"
# include <math.h>

typedef	struct				s_wall
{
	int				x;
	int				y;
	int				size;
}					t_wall;

typedef	struct				s_nc
{
	double					x;
	double					y;
}							t_nc;

typedef	struct				s_vec
{
	double				x;
	double				y;
	double				rot;
}					t_vec;

typedef	struct				s_ray
{
	t_nc				pos;
	t_nc				dir;
	t_pixsdl			mapos;
	t_nc				sd;
	t_nc				dlt;
	double				dist;
	int					incx;
	int					incy;
	char				side;
	char				stop;
}					t_ray;

typedef	struct		s_map
{
	SDL_Surface		*map;
	SDL_Rect		floor;
	SDL_Rect		sky;
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
	char			dep[4];
	char			rot[4];
}					t_player;

typedef	struct		s_inf
{
	int				win;
	int				level;
	char			*mappath;
}					t_inf;

typedef	struct		s_game
{
	t_map			*level;
	t_player		*player;
	t_inf			*inf;
	t_envsdl		*sdl;
}					t_game;

/*
** Init structures
*/
void			init_inf(t_inf *inf);
int				init_level(t_map *level, t_inf *inf, t_envsdl *sdl);
void			init_player(t_player *player);

/*
** Map functions
*/
void			map_iter(t_map *map, t_game *wolf, Uint32 color, \
				void (*f)(t_pixsdl pix, t_game *wolf, t_map *map));

/*
** Event functions
*/
void			ft_mouse(t_envsdl *sdl, void *data);
void			ft_keyboard(t_envsdl *sdl, SDL_Keysym k, void *data);
#endif
