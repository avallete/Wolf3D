/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_sdl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 09:23:06 by avallete          #+#    #+#             */
/*   Updated: 2015/03/12 10:24:49 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sdl.h>

static void		draw_dy(SDL_Surface *s, t_pixsdl *start, int *dir)
{
	int err;
	int i;

	i = 1;
	err = dir[1] / 2;
	while (i <= dir[1])
	{
		start->y += dir[3];
		err += dir[0];
		if (err >= dir[1])
		{
			err -= dir[1];
			start->x += dir[2];
		}
		i++;
		draw_pix_sdl(s, start);
	}
}

static void		draw_dx(SDL_Surface *s, t_pixsdl *start, int *dir)
{
	int err;
	int i;

	i = 1;
	err = dir[0] / 2;
	while (i <= dir[0])
	{
		start->x += dir[2];
		err += dir[1];
		if (err >= dir[0])
		{
			err -= dir[0];
			start->y += dir[3];
		}
		i++;
		draw_pix_sdl(s, start);
	}
}

void			draw_line_sdl(SDL_Surface *s, t_pixsdl start, t_pixsdl end)
{
	int dir[4];

	dir[0] = abs(end.x - start.x);
	dir[1] = abs(end.y - start.y);
	dir[2] = (dir[0] > 0) ? 1 : -1;
	dir[3] = (dir[1] > 0) ? 1 : -1;
	draw_pix_sdl(s, &start);
	if (dir[0] > dir[1])
		draw_dx(s, &start, dir);
	else
		draw_dy(s, &start, dir);
}
