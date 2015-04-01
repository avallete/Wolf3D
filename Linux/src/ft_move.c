/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 16:25:45 by avallete          #+#    #+#             */
/*   Updated: 2015/04/01 12:27:34 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

static int			ft_checkpix(t_game *e, int x, int y)
{
	t_pixsdl	test;

	ft_getpix(e->level->map, &test, x, y);
	if (test.color == SPACE)
		return (1);
	return (0);
}

static void			dep(t_game *e)
{
	double		dir;

	if (e->player->dep[0])
	{
		dir = 0.1 * e->player->dep[0];
		if (ft_checkpix(e, PLRPOS(e).x, PLRPOS(e).y + e->player->dir.y * dir))
			e->player->pos.y += e->player->dir.y * dir;
		if (ft_checkpix(e, PLRPOS(e).x + e->player->dir.x * dir, PLRPOS(e).y))
			e->player->pos.x += e->player->dir.x * dir;
		e->player->map.x = (int)e->player->pos.x;
		e->player->map.y = (int)e->player->pos.y;
	}
	if (e->player->dep[1])
	{
		dir = 0.1 * e->player->dep[1];
		if (ft_checkpix(e, PLRPOS(e).x, PLRPOS(e).y + e->player->plan.y * dir))
			e->player->pos.y += e->player->plan.y * dir;
		if (ft_checkpix(e, PLRPOS(e).x + e->player->plan.x * dir, PLRPOS(e).y))
			e->player->pos.x += e->player->plan.x * dir;
		e->player->map.x = (int)e->player->pos.x;
		e->player->map.y = (int)e->player->pos.y;
	}
}

static void			rot(t_game *e)
{
	t_nc		oldir;
	t_nc		oldplan;
	double		dirrot;

	dirrot = 0.15 * e->player->rot[0];
	oldir.x = e->player->dir.x;
	oldplan.x = e->player->plan.x;
	e->player->dir.x = e->player->dir.x * cos(dirrot) -\
						e->player->dir.y * sin(dirrot);
	e->player->dir.y = oldir.x * sin(dirrot) + e->player->dir.y * cos(dirrot);
	e->player->plan.x = e->player->plan.x * cos(dirrot) -\
						e->player->plan.y * sin(dirrot);
	e->player->plan.y = oldplan.x * sin(dirrot) +\
						e->player->plan.y * cos(dirrot);
}

void				move(t_game *e)
{
	if (e->player->dep[0] || e->player->dep[1])
		dep(e);
	if (e->player->rot[0])
		rot(e);
}
