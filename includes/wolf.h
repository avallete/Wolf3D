#ifndef WOLF_H
#define WOLF_H
# include <SDL/SDL.h>
# include <SDL2/SDL.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# define WINX		500
# define WINY		500
# define BPP		32
# define WIN(e, win)	e->surfaces->win

typedef struct		s_win
{
	SDL_Surface	*wolf;
	SDL_Surface	*screen;
}			t_win;

typedef	struct		s_env
{
	t_win		*surfaces;
}			t_env;
#endif
