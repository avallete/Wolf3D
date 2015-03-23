/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_wchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 09:56:27 by avallete          #+#    #+#             */
/*   Updated: 2015/03/23 18:08:17 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	print_wchar(va_list list, int *i)
{
	wchar_t c;

	c = va_arg(list, wchar_t);
	i[1] += ft_putwchar(c);
}

void	arg_is_wchar(t_flags *flags, va_list list, int *i)
{
	(void)flags;
	print_wchar(list, i);
}
