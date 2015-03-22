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

static void		check_eventype(t_envsdl *env, void *data, controlf_t *f)
{
	if (EVNT_T(env) == SDL_QUIT)
		env->key->echap = 1;
	else if (EVNT_T(env) == SDL_KEYDOWN || EVNT_T(env) == SDL_KEYUP)
		f[0](env, data);
	else if (CHK_MEVENT(EVNT_T(env)))
		f[1](env, data);
	else if (CHK_CEVENT(EVNT_T(env)))
		f[2](env, data);
}

void			ft_keyhook_sdl(t_envsdl *env, void *data, controlf_t *f)
{
	if (SDL_WaitEvent(&(EVNT(env))) != 0)
	{
		check_eventype(env, data, f);
		while (SDL_PollEvent(&(env->key->events)) != 0)
			check_eventype(env, data, f);
	}
}
