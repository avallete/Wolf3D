# include "wolf.h"

void	init_screen(t_env *env)
{
	WIN(env, win) = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINX, WINY, SDL_WINDOW_FULLSCREEN);
	SDL_Delay(2000);
}

int	main(int argc, char *argv[])
{
	t_env	env;
	t_win	sur;

	sur.wolf = NULL;
	sur.screen = NULL;
	sur.win = NULL;
	env.surfaces = &sur;
	if (argc && argv)
	{
		if ((SDL_Init(SDL_INIT_EVERYTHING)) > -1)
		{
			init_screen(&env);
			SDL_Quit();
		}
		else
			ft_putsterr("SDL could not initialize\n");
	}
	return (0);
}
