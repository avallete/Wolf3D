/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 10:19:12 by avallete          #+#    #+#             */
/*   Updated: 2015/01/17 11:11:37 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int ft_printf(const char *format, ...)
{
	va_list list;
	va_list cp;
	int		ret;

	ret = 0;
	if (check_exstr(format))
	{
		va_start(list, format);
		va_copy(cp, list);
		if (ft_strchr(format, '%'))
			ret = found_flags(format, list);
		else
		{
			ft_putstr(format);
			ret = ft_strlen(format);
		}
		va_end(list);
		va_end(cp);
	}
	return (ret);
}
