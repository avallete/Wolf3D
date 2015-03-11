# include "ft_SDL.h"

static int	init_window(t_envSDL *env, void (*f)(t_envSDL *env))
{
	WIN(env, win) = SDL_CreateWindow(WINNAME, SDL_WINDOWPOS_CENTERED,\
	SDL_WINDOWPOS_CENTERED, WINX(env), WINY(env), SDL_WINDOW_SHOWN);
	if ((WIN(env, win)))
	{
		WIN(env, screen) = SDL_GetWindowSurface(WIN(env, win));
		SDL_SetSurfaceRLE(WIN(env, screen), 1);
		SDL_FillRect(WIN(env, screen), NULL, 0);
		SDL_UpdateWindowSurface(WIN(env, win));
		f(env);
		SDL_DestroyWindow(WIN(env, win));
		SDL_Quit();
		return (0);
	}
	else
	{
		ft_putsterr("Initialize window error, retry again !");
		return (-1);
	}
}

void	ft_launchSDL(void (*f)(t_envSDL *env), size_t wx, size_t wy, int bpp)
{
	t_envSDL	env;
	t_winSDL	sur;
	t_keySDL	k;

	sur.screen = NULL;
	sur.hwscreen = NULL;
	sur.win = NULL;
	sur.WinX = wx;
	sur.WinY = wy;
	sur.Bpp = bpp;
	k.echap = 0;
	env.surfaces = &sur;
	env.key = &k;
	init_window(&env, f);
}
