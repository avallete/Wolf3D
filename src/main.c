# include "wolf.h"

void	keyboard_keys(t_env *env)
{
	if (env->key->events.key.keysym.sym == SDLK_ESCAPE)
		env->key->echap = 1;
}

void	key_hook(t_env *env)
{
	while(SDL_PollEvent(&(env->key->events)) != 0)
	{
		if (env->key->events.type == SDL_QUIT)
			env->key->echap = 1;
		else if (env->key->events.type == SDL_KEYDOWN)
			keyboard_keys(env);
	}
}

void	play_it(t_env *env)
{
	while (!(env->key->echap))
	{
		key_hook(env);
	}
}

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
}

int	main(int argc, char *argv[])
{
	t_env	env;
	t_win	sur;
	t_key	k;

	sur.screen = NULL;
	sur.win = NULL;
	k.echap = 0;
	env.surfaces = &sur;
	env.key = &k;
	if (argc && argv)
	{
		if ((SDL_Init(SDL_INIT_EVERYTHING)) > -1)
		{
			init_screen(&env);
			play_it(&env);
			SDL_DestroyWindow(sur.win);
			SDL_Quit();
		}
		else
			ft_putsterr("SDL could not initialize\n");
	}
	return (0);
}
