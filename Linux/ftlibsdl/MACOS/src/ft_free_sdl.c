/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 09:24:03 by avallete          #+#    #+#             */
/*   Updated: 2015/03/12 10:25:49 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void	ft_free_sdl(t_envsdl *sdl)
{
	if (WIN(sdl, screen))
		SDL_FreeSurface(WIN(sdl, screen));
	if (WIN(sdl, hwscreen))
		SDL_FreeSurface(WIN(sdl, hwscreen));
}
