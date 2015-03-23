/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 10:33:11 by avallete          #+#    #+#             */
/*   Updated: 2015/03/15 14:32:00 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SDL_H
# define FT_SDL_H
# include <SDL.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# define WINNAME	"SDL_WIN"
# define WIN(e, win)	e->surfaces->win
# define WINX(e)	e->surfaces->winx
# define WINY(e)	e->surfaces->winy
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
# define CHK_CAXMOT(e) (e == SDL_CONTROLLERAXISMOTION  || e == SDL_JOYAXISMOTION ? 1 : 0)
# define CHK_CBTDOW(e) (e == SDL_CONTROLLERBUTTONDOWN || e == SDL_JOYBUTTONDOWN ? 1 : 0)
# define CHK_CEVENT(e) (CHK_CAXMOT(e) || CHK_CBTDOW(e) ? 1 : 0)

typedef	struct		s_pixsdl
{
	int				x;
	int				y;
	Uint32				color;
}					t_pixsdl;

typedef struct		s_keysdl
{
	char			echap;
	SDL_Event		events;
}					t_keysdl;

typedef struct		s_winsdl
{
	SDL_Surface		*screen;
	SDL_Surface		*hwscreen;
	SDL_Window		*win;
	size_t			winx;
	size_t			winy;
	int				bpp;
}					t_winsdl;

typedef	struct		s_envsdl
{
	t_winsdl		*surfaces;
	t_keysdl		*key;
}					t_envsdl;

typedef void		(*controlf_t)(t_envsdl *env, void *data);

/*
**The first function init and expose a window and she take a pointer function
**in argument. This function need to loop for window stay open.
**The wx and wy is Hight and lenght of created window. bpp need to be 4
*/
void		ft_launch_sdl(void (*f)(t_envsdl *e), size_t wx, size_t wy, int bp);

/*
**Two functions for events. First func just call the ptr function (like print)
**Second function call _sdl_PollEvent and call func key for keyboard event
**and mouse functions for mouse event.
*/
void		ft_expose_sdl(t_envsdl *env, void (*f)(t_envsdl *env));
void		ft_keyhook_sdl(t_envsdl *env, void *data, controlf_t *f);

/*
** Function for load/optimize stuff and check errors more easy
*/
SDL_Surface	*ft_loadbmp_sdl(t_envsdl *env, const char *path);
SDL_Rect	ft_newrect_sdl(int x, int y, size_t width, size_t hight);
int		ft_getpix(SDL_Surface *img, t_pixsdl *pix, int x, int y);

/*
** Draw some stuf
*/
void		draw_pix_sdl(SDL_Surface *surface, t_pixsdl *pix);
void		draw_line_sdl(SDL_Surface *s, t_pixsdl start, t_pixsdl end);

/*
** Free all
*/
void		ft_free_sdl(t_envsdl *sdl);
#endif
