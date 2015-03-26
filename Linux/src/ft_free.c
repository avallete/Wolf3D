/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 12:11:02 by avallete          #+#    #+#             */
/*   Updated: 2015/03/26 16:40:07 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

void	ft_free_wolf(t_game *e)
{
	if (e->inf->mappath)
		free(e->inf->mappath);
	if (e->level->map)
		SDL_FreeSurface(e->level->map);
	if (e->joy)
		SDL_JoystickClose(e->joy);
}
