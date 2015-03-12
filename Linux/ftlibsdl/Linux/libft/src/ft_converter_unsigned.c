/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 13:35:01 by avallete          #+#    #+#             */
/*   Updated: 2015/01/16 11:42:29 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_putlnbr(unsigned long long int nbr)
{
	if (nbr <= 9)
		ft_putchar(nbr + '0');
	else
	{
		ft_putlnbr(nbr / 10);
		ft_putlnbr(nbr % 10);
	}
}

int		ft_lnbrlen(unsigned long long int nbr)
{
	int i;

	i = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	cast_unsigned(unsigned long long int *c, va_list list, t_flags *flags)
{
	if (flags->formf == 'h' && flags->formt == 'h' && flags->type != 'U')
		*c = (unsigned char)va_arg(list, int);
	else if (flags->formf == 'h')
		*c = (unsigned short)va_arg(list, int);
	else
		*c = va_arg(list, unsigned long long int);
}

void	print_unsigned(t_flags *flags, va_list list, int *i)
{
	unsigned long long int	pt;
	int						size;

	cast_unsigned(&pt, list, flags);
	size = ft_lnbrlen(pt);
	if (flags->min_size > size + flags->prec)
		ft_filler(' ', flags->min_size - flags->prec);
	if (flags->prec)
	{
		ft_filler('0', flags->prec - size);
		size += flags->prec - size;
	}
	if (flags->min_size > flags->prec + size)
		size += flags->min_size - size;
	ft_putlnbr(pt);
	i[1] += size;
}

void	arg_is_unsigned(t_flags *flags, va_list list, int *i)
{
	if ((!(flags->optdot)) || (flags->optdot && flags->prec))
	{
		if (flags->type == 'u' || flags->type == 'U')
			print_unsigned(flags, list, i);
	}
}
