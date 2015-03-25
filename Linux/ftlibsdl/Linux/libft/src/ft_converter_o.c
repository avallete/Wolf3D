/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 11:16:08 by avallete          #+#    #+#             */
/*   Updated: 2015/01/16 12:49:38 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	print_loct(t_flags *flags, int *i, unsigned long long pt, char *str)
{
	int size;

	size = 0;
	pt > 0 && flags->optsharp ? (size += 1) : (size += 0);
	ft_linttoct(pt, str);
	size += ft_strlen(str);
	if (flags->min_size > size + flags->prec)
		ft_filler(' ', flags->min_size - flags->prec);
	if (flags->prec)
	{
		ft_filler('0', flags->prec - size);
		size += flags->prec - size;
	}
	ft_putstr(str);
	if (flags->min_size > flags->prec + size)
		size += flags->min_size - size;
	i[1] += size;
}

void	print_octal(t_flags *flags, va_list list, int *i)
{
	unsigned long long int	pt;
	char					str[23];
	int						size;

	ft_bzero(str, 23);
	cast_octal(&pt, list, flags);
	size = 0;
	if (pt > 0 && flags->optsharp)
	{
		ft_putchar('0');
		size++;
	}
	if ((flags->type == 'O' && pt < ULONG_MAX && pt \
	!= (unsigned long long)LONG_MIN) || (flags->type == 'o' && pt < LONG_MAX))
		print_loct(flags, i, pt, str);
	else
	{
		size += max_value(flags, pt);
		i[1] += size;
	}
}

void	cast_octal(unsigned long long int *c, va_list list, t_flags *flags)
{
	if (flags->formf == 'h' && flags->formt == 'h' && flags->type != 'O')
		*c = (unsigned char)va_arg(list, int);
	else if (flags->formf == 'h')
		*c = (unsigned short)va_arg(list, int);
	else
		*c = (unsigned long long int)va_arg(list, unsigned long long int);
}

void	arg_is_octal(t_flags *flags, va_list list, int *i)
{
	if ((!(flags->optdot)) || (flags->optdot && flags->prec) || flags->optsharp)
	{
		if (flags->type == 'o' || flags->type == 'O')
			print_octal(flags, list, i);
	}
}
