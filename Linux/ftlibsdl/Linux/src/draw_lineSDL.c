#include <ft_SDL.h>

static void	draw_dy(SDL_Surface *s, t_pixSDL *start, int *dir)
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
			draw_pixSDL(s, start);
			start->x += dir[2];
		}
		i++;
		draw_pixSDL(s, start);
	}
}

static void	draw_dx(SDL_Surface *s, t_pixSDL *start, int *dir)
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
			draw_pixSDL(s, start);
			start->y += dir[3];
		}
		i++;
		draw_pixSDL(s, start);
	}
}


void	draw_lineSDL(SDL_Surface *s, t_pixSDL start, t_pixSDL end)
{
	int dir[4];

	dir[0] = abs(end.x - start.x);
	dir[1] = abs(end.y - start.y);
	dir[2] = (dir[0] > 0) ? 1 : -1;
	dir[3] = (dir[1] > 0) ? 1 : -1;
	draw_pixSDL(s, &start);
	if (dir[0] > dir[1])
		draw_dx(s, &start, dir);
	else
		draw_dy(s, &start, dir);
}
