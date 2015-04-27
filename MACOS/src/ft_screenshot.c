/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 12:12:26 by avallete          #+#    #+#             */
/*   Updated: 2015/04/01 12:30:29 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wolf.h"

static int		test_filexist(char *path)
{
	int fd;

	fd = 0;
	if ((fd = open(path, O_RDONLY)) >= 0)
	{
		close(fd);
		return (1);
	}
	return (0);
}

static int		test_scrfile(t_game *e)
{
	char	*path;
	char	*itoa;
	char	*tmp;
	int		ret;

	itoa = ft_itoa(e->inf->nb);
	tmp = ft_strjoin(itoa, ".bmp");
	path = ft_strjoin(e->inf->scrspath, tmp);
	ret = test_filexist(path);
	free(itoa);
	free(tmp);
	free(path);
	return (ret);
}

void			save_map(t_game *e)
{
	char *path;
	char *itoa;
	char *tmp;

	while (test_scrfile(e))
		e->inf->nb++;
	itoa = ft_itoa(e->inf->nb);
	tmp = ft_strjoin(itoa, ".bmp");
	path = ft_strjoin(e->inf->scrspath, tmp);
	if (SDL_SaveBMP(e->level->map, path) >= 0)
		ft_printf("Save screenshot : %s\n", path);
	else
		ft_printf("Couldn't save screenshot : %s\n", path);
	free(itoa);
	free(tmp);
	free(path);
	SDL_Delay(500);
}
