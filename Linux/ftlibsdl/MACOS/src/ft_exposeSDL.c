#include <ft_SDL.h>

void	ft_exposeSDL(t_envSDL *env, void (*f)(t_envSDL* env))
{
	if (f)
		f(env);
	else
		ft_putsterr("Invalid function pass at exposeSDL\n");
}
