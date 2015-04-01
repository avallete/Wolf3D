/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_sdl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 09:25:04 by avallete          #+#    #+#             */
/*   Updated: 2015/04/01 13:03:22 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

static int		init_window(t_envsdl *e, void (*f)(t_envsdl *env))
{
	WIN(e, win) = SDL_CreateWindow(WINNAME, SDL_WINDOWPOS_CENTERED,\
			SDL_WINDOWPOS_CENTERED, WINX(e), WINY(e), SDL_WINDOW_SHOWN);
	if ((WIN(e, win)))
	{
		WIN(e, screen) = SDL_GetWindowSurface(WIN(e, win));
		SDL_SetSurfaceRLE(WIN(e, screen), 1);
		SDL_FillRect(WIN(e, screen), NULL, 0);
		SDL_UpdateWindowSurface(WIN(e, win));
		f(e);
		ft_free_sdl(e);
		SDL_DestroyWindow(WIN(e, win));
		SDL_Quit();
		return (0);
	}
	else
	{
		ft_putsterr("Initialize window error, retry again !");
		return (-1);
	}
}

static void		grep_joystick(t_envsdl *env)
{
	const char *map;

	if (SDL_NumJoysticks() > 0)
	{
		ft_printf("Joystick %s detected\n", SDL_JoystickName(0));
		env->key->joy = SDL_JoystickOpen(0);
		if (env->key->joy)
		{
			ft_printf("Joystick 0 opened with sucess\n");
			map = SDL_GameControllerMappingForGUID(\
					SDL_JoystickGetGUID(env->key->joy));
			if (SDL_GameControllerAddMapping(map))
			{
				SDL_JoystickEventState(SDL_ENABLE);
			}
		}
	}
}

void			ft_launch_sdl(void (*f)(t_envsdl *e), size_t wx,\
				size_t wy, int bp)
{
	t_envsdl	env;
	t_winsdl	sur;
	t_keysdl	k;

	sur.screen = NULL;
	sur.hwscreen = NULL;
	sur.win = NULL;
	sur.winx = wx;
	sur.winy = wy;
	sur.bpp = bp;
	k.echap = 0;
	k.joy = NULL;
	env.surfaces = &sur;
	env.key = &k;
	grep_joystick(&env);
	init_window(&env, f);
}
