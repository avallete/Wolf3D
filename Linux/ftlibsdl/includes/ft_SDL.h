#ifndef FT_SDL_H
#define FT_SDL_H
# include <SDL.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# define WINNAME	"SDL_WIN"
# define WIN(e, win)	e->surfaces->win
# define WINX(e)	e->surfaces->WinX
# define WINY(e)	e->surfaces->WinY
# define SX(e)		e->w
# define SY(e)		e->h
# define IMG_MAX(e) ((SX(e) * SY(e)) * e->format->BytesPerPixel)
# define CENTERX(e) (WINX(e) / 2)
# define CENTERY(e) (WINY(e) / 2)
# define PLACE_IMG(x, y, e) ((y * e->pitch) + (x * e->format->BytesPerPixel))
# define EVNT(e)	e->key->events
# define EVNT_T(e)	EVNT(e).type
# define EVNT_KEY(e)	EVNT(e).key.keysym
# define CHK_MMOTION(e) (e == SDL_MOUSEMOTION ? 1 : 0)
# define CHK_MBUTON(e) (e == SDL_MOUSEBUTTONDOWN ? 1 : 0)
# define CHK_MWHEL(e) (e == SDL_MOUSEWHEEL ? 1 : 0)
# define CHK_MEVENT(e) (CHK_MWHEL(e) || CHK_MBUTON(e) || CHK_MMOTION(e) ? 1 : 0)
# define CHK_CAXMOT(e) (e == SDL_CONTROLLERAXISMOTION ? 1 : 0)
# define CHK_CBTDOW(e) (e == SDL_CONTROLLERBUTTONDOWN ? 1 : 0)
# define CHK_CEVENT(e) (CHK_CAXMOT(e) || CHK_CBTDOW(e) ? 1 : 0)

typedef	struct		t_pixSDL
{
	int		x;
	int		y;
	Uint32		color;
}			t_pixSDL;

typedef struct		s_keySDL
{
	char		echap;
	SDL_Event	events;
}			t_keySDL;

typedef struct		s_winSDL
{
	SDL_Surface	*screen;
	SDL_Surface	*hwscreen;
	SDL_Window	*win;
	size_t		WinX;
	size_t		WinY;
	int		Bpp;
}			t_winSDL;

typedef	struct		s_envSDL
{
	t_winSDL	*surfaces;
	t_keySDL	*key;
}			t_envSDL;

/*
**The first function init and expose a window and she take a pointer function
**in argument. This function need to loop for window stay open.
**The wx and wy is Hight and lenght of created window. bpp need to be 4
*/
void	ft_launchSDL(void (*f)(t_envSDL *env), size_t wx, size_t wy, int bpp);

/*
**Two functions for events. First func just call the ptr function (like print)
**Second function call SDL_PollEvent and call func key for keyboard event
**and mouse functions for mouse event.
*/
void	ft_exposeSDL(t_envSDL *env, void (*f)(t_envSDL *env));
void	ft_keyhookSDL(t_envSDL *env, void *data, \
		void (*key)(t_envSDL *env, SDL_Keysym c, void *data), \
		void (*mouse)(t_envSDL *env, void *data), \
		void (*joy)(t_envSDL *env, void *data));

/*
** Function for load/optimize stuff and check errors more easy
*/
SDL_Surface	*ft_loadbmpSDL(t_envSDL *env, const char *path);
SDL_Rect	ft_newrectSDL(int x, int y, size_t width, size_t hight);
t_pixSDL	ft_getpix(SDL_Surface *img, int x, int y);

/*
** Draw some stuf
*/
void	draw_pixSDL(SDL_Surface *surface, t_pixSDL *pix);
void	draw_lineSDL(SDL_Surface *s, t_pixSDL start, t_pixSDL end);

/*
** Free all
*/
void	ft_freeSDL(t_envSDL *sdl);
#endif
