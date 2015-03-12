# include "ft_SDL.h"

static void	check_eventype(t_envSDL *env, void *data, \
		void (*key)(t_envSDL *env, SDL_Keysym c, void *data), \
		void (*mouse)(t_envSDL *env, void *data), \
		void (*joy)(t_envSDL *env, void *data))
{
		if (EVNT_T(env) == SDL_QUIT)
			env->key->echap = 1;
		else if (EVNT_T(env) == SDL_KEYDOWN || EVNT_T(env) == SDL_KEYUP)
			key(env, EVNT_KEY(env), data);
		else if (CHK_MEVENT(EVNT_T(env)))
			mouse(env, data);
		else if (CHK_CEVENT(EVNT_T(env)))
			joy(env, data);

}

void	ft_keyhookSDL(t_envSDL *env, void *data, \
		void (*key)(t_envSDL *env, SDL_Keysym c, void *data), \
		void (*mouse)(t_envSDL *env, void *data), \
		void (*joy)(t_envSDL *env, void *data))
{
	if (SDL_WaitEvent(&(EVNT(env))) != 0)
	{
		check_eventype(env, data, key, mouse, joy);
		while (SDL_PollEvent(&(env->key->events)) != 0)
			check_eventype(env, data, key, mouse, joy);
	}
}
