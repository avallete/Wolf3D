/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 12:55:17 by avallete          #+#    #+#             */
/*   Updated: 2015/01/16 12:56:24 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		print_int_fill(t_flags *flags, int *i, int c)
{
	int size;

	size = ft_nbrlen(c);
	if (flags->prec)
		size += (flags->prec - size);
	if ((flags->optplus && c > 0) || c < 0)
		size += 1;
	if (flags->min_size && size < flags->min_size)
		print_int_opt(flags, c, size, i);
	else
		print_no_min(flags, i, c);
	if ((flags->optplus && c >= 0) || c < 0)
		size -= 1;
	if (c < 0)
		size += 1;
	return (size);
}

void	print_int_opt(t_flags *flags, int c, int size, int *i)
{
	if (flags->optspace)
	{
		ft_putchar(' ');
		i[1] += 1;
		size += 1;
	}
	i[1] += flags->min_size - size;
	if (flags->optmin)
		print_int_rev(flags, i, size, c);
	else
	{
		print_plus(flags, i, c, &size);
		if (flags->optzero || flags->prec)
			c < 0 ? (c = -c, ft_putchar('-')) : (c += 0);
		if (flags->min_size)
			fill_it(flags, flags->min_size - size);
		if (flags->prec)
			ft_filler('0', flags->prec - ft_nbrlen(c));
		ft_putnbr(c);
	}
}
