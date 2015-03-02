# include "wolf.h"

void	init_screen(t_env *env)
{
	WIN(env, win) = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED,\
	SDL_WINDOWPOS_CENTERED, WINX, WINY, SDL_WINDOW_SHOWN);
	if ((WIN(env, win)))
	{
		WIN(env, screen) = SDL_GetWindowSurface(WIN(env, win));
		SDL_FillRect(WIN(env, screen), NULL, SDL_MapRGB(WIN(env, screen)->format, 0xFF, 0, 0xFF));
		SDL_UpdateWindowSurface(WIN(env, win));
	}
	else
		ft_putsterr("Initialize window error, retry again !");
	SDL_Delay(5000);
}

int	main(int argc, char *argv[])
{
	t_env	env;
	t_win	sur;

	sur.screen = NULL;
	sur.win = NULL;
	env.surfaces = &sur;
	if (argc && argv)
	{
		if ((SDL_Init(SDL_INIT_EVERYTHING)) > -1)
		{
			init_screen(&env);
			SDL_DestroyWindow(sur.win);
			SDL_Quit();
		}
		else
			ft_putsterr("SDL could not initialize\n");
	}
	return (0);
}
