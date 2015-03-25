/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 12:46:29 by avallete          #+#    #+#             */
/*   Updated: 2015/01/16 12:48:11 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		max_ul(t_flags *flags)
{
	int size;

	size = 22;
	if (flags->min_size > size + flags->prec)
		ft_filler(' ', flags->min_size - flags->prec);
	if (flags->prec)
	{
		ft_filler('0', flags->prec - size);
		size += flags->prec - size;
	}
	ft_putstr("1777777777777777777777");
	if (flags->min_size > flags->prec + size)
		size += flags->min_size - size;
	return (size);
}

int		max_l(t_flags *flags)
{
	int size;

	size = 11;
	if (flags->min_size > size + flags->prec)
		ft_filler(' ', flags->min_size - flags->prec);
	if (flags->prec)
	{
		ft_filler('0', flags->prec - size);
		size += flags->prec - size;
	}
	ft_putstr("37777777777");
	if (flags->min_size > flags->prec + size)
		size += flags->min_size - size;
	return (size);
}

int		max_uol(t_flags *flags)
{
	int size;

	size = 22;
	if (flags->min_size > size + flags->prec)
		ft_filler(' ', flags->min_size - flags->prec);
	if (flags->prec)
	{
		ft_filler('0', flags->prec - size);
		size += flags->prec - size;
	}
	ft_putstr("1000000000000000000000");
	if (flags->min_size > flags->prec + size)
		size += flags->min_size - size;
	return (size);
}

int		max_value(t_flags *flags, unsigned long long nb)
{
	int size;

	size = 0;
	if ((flags->type == 'O' || flags->formf == 'l' || flags->formf == 'j' \
		|| flags->formf == 'z') && nb >= ULONG_MAX)
		size = max_ul(flags);
	else if ((flags->type == 'o' && flags->formf == '\0') && nb >= LONG_MAX)
		size = max_l(flags);
	else
		size = max_uol(flags);
	return (size);
}
