/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changelevel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 12:14:41 by avallete          #+#    #+#             */
/*   Updated: 2015/04/04 13:12:42 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

void	change_level(t_game *e, int mode)
{
	e->inf->win = 1;
	e->inf->nb += mode;
	ft_printf("Change level to map%d.bmp\n", e->inf->nb);
	SDL_Delay(300);
}

void	ft_check_level(t_envsdl *sdl, t_game *wolf, SDL_Keysym k)
{
	if (EVNT_T(sdl) == SDL_KEYDOWN && k.sym == SDLK_n)
		change_level(wolf, 1);
	if (EVNT_T(sdl) == SDL_KEYDOWN && k.sym == SDLK_b)
		change_level(wolf, -1);
}

void	sdl_surfreesec(SDL_Surface *src)
{
	if (src)
	{
		SDL_LockSurface(src);
		SDL_FreeSurface(src);
		SDL_UnlockSurface(src);
	}
}
