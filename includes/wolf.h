#ifndef WOLF_H
#define WOLF_H
# include <SDL2/SDL.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# define WINX		500
# define WINY		500
# define BPP		32
# define WIN(e, win)	e->surfaces->win

typedef struct		s_key
{
	char		echap;
	SDL_Event	events;
}			t_key;

typedef struct		s_win
{
	SDL_Surface	*screen;
	SDL_Window	*win;
}			t_win;

typedef	struct		s_env
{
	t_win		*surfaces;
	t_key		*key;
}			t_env;
#endif
