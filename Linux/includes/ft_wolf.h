#ifndef FT_WOLF_H
# define FT_WOLF_H
# define WALL 0
# define FOV 60
# define WALLSIZE 64
# define SPACE 0xff
# define PLAYER(e)	e->player
# define PLRPOS(e)	e->player_>pos
# define CAM(e)		e->player->cam
# define SKY(e)		e->level->sky
# define MAPLVL(e)	e->level->map
# define PLAN(e)	e->player->plan
# define FLOOR(e) e->level->floor
# define DIST(x) ((x / (tan(30 * M_PI / 180))))
# define RAD(x)	(x * 0.017453292519943)
# include "ft_sdl.h"
# include <math.h>
# include <stdio.h>

typedef	struct				s_wall
{
	int				x;
	int				y;
	int				size;
}					t_wall;

typedef	struct				s_vec
{
	int				x;
	int				y;
}					t_vec;

typedef	struct		s_cam
{
	double				x;
	double				y;
	double				dx;
	double				dy;
}					t_cam;

typedef	struct		s_nc
{
	double			x;
	double			y;
}					t_nc;

typedef	struct				s_ray
{
	int				px;
	int				py;
	double				x;
	double				y;
	double				dx;
	double				dy;
	double				dltx;
	double				dlty;
	double				sdx;
	double				sdy;
	int				incx;
	int				incy;
	char				side;
}					t_ray;

typedef	struct		s_map
{
	SDL_Surface		*map;
	SDL_Rect		floor;
	SDL_Rect		sky;
}					t_map;

typedef	struct		s_player
{
	t_vec			pos;
	t_nc			plan;
	t_cam			cam;
	double			hight;
	double			dist;
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
