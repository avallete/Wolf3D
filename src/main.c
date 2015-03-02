# include "wolf.h"

void	init_screen(t_env *env)
{
	WIN(env, screen) = SDL_SetVideoMode(WINX, WINY, BPP, SDL_SWSURFACE);
	WIN(env, wolf) = SDL_LoadBMP("src/wolf.bmp");
	SDL_BlitSurface(WIN(env, wolf), NULL, WIN(env, screen), NULL);
	SDL_Flip(WIN(env, screen));
	SDL_Delay(2000);
}

int	main(int argc, char *argv[])
{
	t_env	env;
	t_win	sur;

	sur.wolf = NULL;
	sur.screen = NULL;
	env.surfaces = &sur;
	if (argc && argv)
	{
	if ((SDL_Init(SDL_INIT_EVERYTHING)) > -1)
	{
		init_screen(&env);
	}
	}
	return (0);
}
