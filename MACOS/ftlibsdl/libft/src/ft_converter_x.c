/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 10:37:29 by avallete          #+#    #+#             */
/*   Updated: 2015/01/17 12:10:12 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_inttohexa(unsigned long long int nb, char *str, char *hex)
{
	int i;

	i = 1;
	if (nb > 0)
	{
		while ((nb >> (4 * i)) > 0 && i < 16)
			i++;
		i--;
		while (nb > 0)
		{
			str[i--] = hex[(nb & 0xF)];
			nb >>= 4;
		}
	}
	else
		str[0] = '0';
}

void	cast_hexa(unsigned long long int *c, va_list list, t_flags *flags)
{
	if (flags->formf == 'h' && flags->formt == 'h')
		*c = (unsigned char)va_arg(list, int);
	else if (flags->formf == 'h' && flags->formt == '\0')
		*c = (unsigned short)va_arg(list, int);
	else
		*c = va_arg(list, unsigned long long int);
}

void	print_x(t_flags *flags, va_list list, int *i)
{
	unsigned long long int	pt;
	char					str[16];

	ft_bzero(str, 16);
	cast_hexa(&pt, list, flags);
	if (pt > 0 && flags->optsharp)
		flags->type == 'x' ? ft_putstr("0x") : ft_putstr("0X"), i[1] += 2;
	flags->type == 'x' ? ft_inttohexa(pt, str, HEXMIN) :\
	ft_inttohexa(pt, str, HEXMAJ);
	if (flags->min_size > (int)(flags->prec + ft_strlen(str)))
	{
		flags->prec ? fill_it(flags, flags->min_size - flags->prec) : \
		fill_it(flags, flags->min_size - ft_strlen(str));
		flags->prec ? (i[1] += flags->min_size - flags->prec) :\
		(i[1] += flags->min_size - ft_strlen(str));
	}
	if (flags->prec)
	{
		ft_filler('0', flags->prec - ft_strlen(str));
		i[1] += flags->prec - ft_strlen(str);
	}
	ft_putstr(str);
	i[1] += ft_strlen(str);
}

void	arg_is_x(t_flags *flags, va_list list, int *i)
{
	if ((!(flags->optdot)) || (flags->optdot && flags->prec))
	{
		if (flags->type == 'x' || flags->type == 'X')
			print_x(flags, list, i);
	}
}
