/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:20:29 by avallete          #+#    #+#             */
/*   Updated: 2015/01/16 12:28:07 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	init_flags(const char *str, t_flags *flags, int *i)
{
	*i += 1;
	check_flg(str, flags, i);
	check_width(str, flags, i);
	check_prec(str, flags, i);
	check_form(str, flags, i);
	check_type(str, flags, i);
}

void	ft_flagstype(t_flags *flags, va_list list, int *i)
{
	if (flags->type == '%')
		arg_is_mod(flags, i);
	if (flags->type == 's' || flags->type == 'S')
		arg_is_string(flags, list, i);
	if (flags->type == 'c' || flags->type == 'C')
		arg_is_char(flags, list, i);
	if (flags->type == 'd' || flags->type == 'i' || flags->type == 'D')
		arg_is_int(flags, list, i);
	if (flags->type == 'p')
		arg_is_ptr(flags, list, i);
	if (flags->type == 'x' || flags->type == 'X')
		arg_is_x(flags, list, i);
	if (flags->type == 'o' || flags->type == 'O')
		arg_is_octal(flags, list, i);
	if (flags->type == 'u' || flags->type == 'U')
		arg_is_unsigned(flags, list, i);
}

void	ft_type_sort(const char *str, t_flags *flags, va_list list, int *i)
{
	if (flags->type != '\0')
		ft_flagstype(flags, list, i);
	else
	{
		if (flags->min_size - 1 > 0)
		{
			if (!(flags->optmin))
			{
				fill_it(flags, flags->min_size - 1);
				i[1] += flags->min_size - 1;
			}
			else
			{
				ft_putchar(str[i[0]]);
				i[1] += flags->min_size;
				i[0] += 1;
				fill_it(flags, flags->min_size - 1);
			}
		}
	}
}

void	ft_arg_sort(const char *str, va_list list, int *i)
{
	t_flags flags;

	ft_bzero(&flags, sizeof(t_flags));
	init_flags(str, &flags, i);
	ft_type_sort(str, &flags, list, i);
}

int		found_flags(const char *str, va_list list)
{
	int i[2];

	i[0] = 0;
	i[1] = 0;
	while (str[i[0]] != '\0')
	{
		if (str[i[0]] == '%')
			ft_arg_sort(str, list, i);
		else
		{
			ft_putchar(str[i[0]]);
			i[1] += 1;
			i[0] += 1;
		}
	}
	return (i[1]);
}
