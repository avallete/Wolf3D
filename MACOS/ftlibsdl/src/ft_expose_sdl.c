/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expose_sdl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 09:23:25 by avallete          #+#    #+#             */
/*   Updated: 2015/03/12 10:25:24 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sdl.h>

void	ft_expose_sdl(t_envsdl *env, void (*f)(t_envsdl *env))
{
	if (f)
		f(env);
	else
		ft_putsterr("Invalid function pass at exposeSDL\n");
}
