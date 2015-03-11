#include "ft_wolf.h"

void	map_iter(t_map *map, t_game *wolf, Uint32 color, \
		void (*f)(t_pixSDL pix, t_game *wolf, t_map *map))
{
	int x;
	int y;
	t_pixSDL pix;

	y = 0;
	while (y < map->map->h)
	{
		x = 0;
		while (x < map->map->w)
		{
			pix = ft_getpix(map->map, x, y);
			if (pix.color == color)
				f(pix, wolf, map);
			x++;
		}
		y++;
	}
}
