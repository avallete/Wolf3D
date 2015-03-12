/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:15:24 by avallete          #+#    #+#             */
/*   Updated: 2015/01/16 12:54:12 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		check_exstr(const char *str)
{
	if (str != NULL && str[0] != '\0')
		return (1);
	else
		return (0);
}

char	*ft_grep_first_number(const char *str, int *i, char *result)
{
	int		e;

	ft_bzero(result, 100);
	e = 0;
	if (ft_isdigit(str[i[0]]))
	{
		while (ft_isdigit(str[i[0]]))
		{
			result[e] = str[i[0]];
			e++;
			i[0] += 1;
		}
	}
	return (result);
}

int		type_cmp(const char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||\
	c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' ||\
	c == 'c' || c == 'C' || c == '%')
		return (1);
	return (0);
}

void	fill_it(t_flags *flags, int size)
{
	if (flags->optzero && !(flags->prec) && (!(flags->optmin)))
		ft_filler('0', size);
	else
		ft_filler(' ', size);
}

void	print_plus(t_flags *flags, int *i, int c, int *size)
{
	if (flags->optplus && c >= 0)
	{
		ft_putchar('+');
		i[1] += 1;
		*size += 1;
	}
}
