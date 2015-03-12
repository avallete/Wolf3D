/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook_sdl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 09:24:43 by avallete          #+#    #+#             */
/*   Updated: 2015/03/12 10:27:12 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

static void		check_eventype(t_envsdl *env, void *data, \
		void (*key)(t_envsdl *env, SDL_Keysym c, void *data), \
		void (*mouse)(t_envsdl *env, void *data))
{
	if (EVNT_T(env) == SDL_QUIT)
		env->key->echap = 1;
	else if (EVNT_T(env) == SDL_KEYDOWN || EVNT_T(env) == SDL_KEYUP)
		key(env, EVNT_KEY(env), data);
	else if (CHK_MEVENT(EVNT_T(env)))
		mouse(env, data);
}

void			ft_keyhook_sdl(t_envsdl *env, void *data, \
		void (*key)(t_envsdl *env, SDL_Keysym c, void *data), \
		void (*mouse)(t_envsdl *env, void *data))
{
	if (SDL_WaitEvent(&(EVNT(env))) != 0)
	{
		check_eventype(env, data, key, mouse);
		while (SDL_PollEvent(&(env->key->events)) != 0)
			check_eventype(env, data, key, mouse);
	}
}
