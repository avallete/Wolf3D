/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 12:00:55 by avallete          #+#    #+#             */
/*   Updated: 2015/04/04 12:30:23 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

void	draw_background(t_game *wolf)
{
	SDL_LockSurface(WIN(wolf->sdl, screen));
	SDL_FillRect(WIN(wolf->sdl, screen), &FLOOR(wolf), 0xff906200);
	SDL_FillRect(WIN(wolf->sdl, screen), &SKY(wolf), 0xff00b89e);
	SDL_UnlockSurface(WIN(wolf->sdl, screen));
}

void	draw_it(t_game *e)
{
	unsigned int	x;
	t_ray			h;

	x = 0;
	h.mapos.x = 0;
	h.mapos.y = 0;
	h.mapos.color = 0;
	while (x < WX(e))
	{
		init_ray(e, x, &h);
		if ((h.mapos.x >= 0 && h.mapos.x < LVX(e)) && h.mapos.y >= 0 &&\
				h.mapos.y < LVY(e))
		{
			while (!h.stop && (h.mapos.x >= 0 && h.mapos.x <= LVX(e)) \
					&& h.mapos.y >= 0 && h.mapos.y <= LVY(e))
				inc_ray(e, &h);
			draw_wall(e, &h, x);
		}
		x++;
	}
}
