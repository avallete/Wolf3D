/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_us.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 17:19:26 by avallete          #+#    #+#             */
/*   Updated: 2015/01/16 17:19:27 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		print_wstr_rev(t_flags *flags, wchar_t *str, int size)
{
	if (flags->optdot && flags->prec)
		ft_putwnstr(str, flags->prec);
	else
		str ? ft_putwstr(str) : ft_putstr("(null)");
	if (flags->min_size > size)
	{
		fill_it(flags, flags->min_size - size);
		size += flags->min_size - size;
	}
	return (size);
}

void	print_wstr(t_flags *flags, va_list list, int *i)
{
	wchar_t	*str;
	int		size;

	size = 0;
	str = va_arg(list, wchar_t*);
	str ? (size = ft_wstrlen(str)) : (size += 6);
	if ((flags->optdot && flags->prec && str))
		size = ft_wnstrlen(str, flags->prec);
	if (!flags->optmin)
	{
		if (flags->min_size >= size)
		{
			fill_it(flags, flags->min_size - size);
			size += flags->min_size - size;
		}
		if (flags->optdot && flags->prec)
			ft_putwnstr(str, flags->prec);
		else
			str ? ft_putwstr(str) : ft_putstr("(null)");
	}
	else
		size = print_wstr_rev(flags, str, size);
	i[1] += size;
}

void	arg_is_wstr(t_flags *flags, va_list list, int *i)
{
	if (!(flags->optdot) || (flags->optdot && flags->prec) || flags->optsharp)
		print_wstr(flags, list, i);
	else if ((flags->optdot && (!(flags->prec)) && flags->min_size))
	{
		fill_it(flags, flags->min_size);
		i[1] += flags->min_size;
	}
}
