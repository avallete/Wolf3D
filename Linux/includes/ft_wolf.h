#ifndef FT_WOLF_H
# define FT_WOLF_H
# define WALL 0
# define WALLSIZE 64
# define SPACE 0xff
# define PLAYER(e) e->player
# define PLRPOS(e) e->player->pos
# define RAY(e) e->player->ray
# define SKY(e) e->level->sky
# define FLOOR(e) e->level->floor
# include "ft_SDL.h"
# include <math.h>

typedef	struct		s_vec
{
	int				x;
	int				y;
}					t_vec;

typedef	struct		s_cam
{
	int				x;
	int				y;
	double			rot;
}					t_cam;

typedef	struct		s_nc
{
	double			x;
	double			y;
}					t_nc;

typedef	struct		s_map
{
	SDL_Surface		*map;
	SDL_Rect		floor;
	SDL_Rect		sky;
}					t_map;

typedef	struct		s_ray
{
	int				cpx;
	int				cpy;
	int				incx;
	int				incy;
	double			px;
	double			py;
	double			dx;
	double			dy;
	double			sdx;
	double			sdy;
	double			dtx;
	double			dty;
}					t_ray;

typedef	struct		s_player
{
	t_vec			pos;
	t_cam			head;
	t_ray			ray;
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
