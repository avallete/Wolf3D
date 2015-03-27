/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadbmp_sdl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 09:25:24 by avallete          #+#    #+#             */
/*   Updated: 2015/03/27 15:42:40 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

SDL_Surface	*ft_loadbmp_sdl(t_envsdl *env, const char *path)
{
	SDL_Surface *imgloaded;
	SDL_Surface *optimize;

	imgloaded = NULL;
	optimize = NULL;
	if (!(imgloaded = SDL_LoadBMP(path)))
		ft_putsterr("Error Loading img\n");
	else if (!(optimize = SDL_ConvertSurface(imgloaded, \
				WIN(env, screen)->format, 0)))
		ft_putsterr("Error Optimize\n");
	if (imgloaded)
		SDL_FreeSurface(imgloaded);
	return (optimize);
}
