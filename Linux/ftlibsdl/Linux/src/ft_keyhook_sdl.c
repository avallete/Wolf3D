/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook_sdl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 09:24:43 by avallete          #+#    #+#             */
/*   Updated: 2015/04/01 12:59:37 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

static void		check_eventype(t_envsdl *env, void *data, t_controlf *f)
{
	if (EVNT_T(env) == SDL_QUIT)
		env->key->echap = 1;
	else if ((EVNT_T(env) == SDL_KEYDOWN || EVNT_T(env) == SDL_KEYUP) && f[0])
		f[0](env, data);
	else if (CHK_MEVENT(EVNT_T(env)) && f[1])
		f[1](env, data);
	else if (CHK_CEVENT(EVNT_T(env)) && f[2])
		f[2](env, data);
	else if (EVNT_T(env) == SDL_SYSWMEVENT && f[3])
		f[3](env, data);
	else if (EVNT_T(env) == SDL_WINDOWEVENT && f[4])
		f[4](env, data);
	else if (EVNT_T(env) == SDL_USEREVENT && f[5])
		f[5](env, data);
}

void			ft_keyhook_sdl(t_envsdl *env, void *data, t_controlf *f)
{
	while (SDL_PollEvent(&(env->key->events)) != 0)
		check_eventype(env, data, f);
	SDL_Delay(K_DELAY);
}
