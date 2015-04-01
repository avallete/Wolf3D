/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rayfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 12:08:21 by avallete          #+#    #+#             */
/*   Updated: 2015/04/01 12:09:41 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

void	init_ray(t_game *e, int x, t_ray *r)
{
	r->incx = 1;
	r->incy = 1;
	PLAYER(e)->cam.x = (2 * x) / ((double)(WX(e))) - 1;
	r->pos.x = PLAYER(e)->pos.x;
	r->pos.y = PLAYER(e)->pos.y;
	r->dir.x = PLAYER(e)->dir.x + PLAYER(e)->plan.x * PLAYER(e)->cam.x;
	r->dir.y = PLAYER(e)->dir.y + PLAYER(e)->plan.y * PLAYER(e)->cam.x;
	r->mapos.x = (int)r->pos.x;
	r->mapos.y = (int)r->pos.y;
	r->mapos.color = 0xff000000;
	r->dlt.y = sqrt(1.0 + (RD(r).x * RD(r).x) / (RD(r).y * RD(r).y));
	r->dlt.x = sqrt(1.0 + (RD(r).y * RD(r).y) / (RD(r).x * RD(r).x));
	RSD(r).x = (RMP(r).x + (1.0 - RP(r).x)) * RDT(r).x;
	RSD(r).y = (RMP(r).y + (1.0 - RP(r).y)) * RDT(r).y;
	RD(r).x < 0 ? (r->incx = -1), \
	(RSD(r).x = (RP(r).x - RMP(r).x) * RDT(r).x) : 0;
	RD(r).y < 0 ? (r->incy = -1), \
	(RSD(r).y = (RP(r).y - RMP(r).y) * RDT(r).y) : 0;
	r->stop = 0;
}

void	inc_ray(t_game *e, t_ray *r)
{
	ft_getpix(e->level->map, &(r->mapos), r->mapos.x, r->mapos.y);
	if (r->mapos.color != SPACE)
		r->stop = 1;
	else
	{
		if (RSD(r).x < RSD(r).y)
		{
			RSD(r).x += RDT(r).x;
			RMP(r).x += r->incx;
			r->side = 0;
		}
		else
		{
			RSD(r).y += RDT(r).y;
			RMP(r).y += r->incy;
			r->side = 1;
		}
		ft_getpix(e->level->map, &(r->mapos), r->mapos.x, r->mapos.y);
		if (r->mapos.color != SPACE)
			r->stop = 1;
	}
}

void	draw_wall(t_game *e, t_ray *r, int x)
{
	t_pixsdl	b;
	t_pixsdl	end;
	int			wallh;

	if (r->side == 0)
		r->dist = fabs((RMP(r).x - RP(r).x + (1 - r->incx) / 2) / RD(r).x);
	else
		r->dist = fabs((RMP(r).y - RP(r).y + (1 - r->incy) / 2) / RD(r).y);
	wallh = abs((int)(WY(e) / r->dist));
	wallh < 0 || wallh > (int)WX(e) ? (wallh = WX(e)) : 0;
	b.x = x;
	b.y = (-wallh / 2) + (WY(e) / 2);
	if (b.y < 0)
		b.y = 0;
	end.x = x;
	end.y = wallh / 2 + WY(e) / 2;
	if (end.y >= (int)WY(e))
		end.y = (int)WY(e);
	define_color(e, r, &b.color, e->player->col);
	draw_line_sdl(WIN(e->sdl, screen), b, end);
}
