/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 17:19:00 by avallete          #+#    #+#             */
/*   Updated: 2015/01/16 17:19:03 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	check_flg(const char *str, t_flags *flags, int *i)
{
	while (str[*i] == '#' || str[*i] == '+' || str[*i] == '0' || \
			str[*i] == '-' || str[*i] == ' ')
	{
		str[*i] == '#' ? (flags->optsharp = 1) : (flags->optsharp += 0);
		str[*i] == '-' ? (flags->optmin = 1) : (flags->optmin += 0);
		str[*i] == '+' ? (flags->optplus = 1) : (flags->optplus += 0);
		str[*i] == '0' ? (flags->optzero = 1) : (flags->optzero += 0);
		str[*i] == ' ' ? (flags->optspace = 1) : (flags->optspace += 0);
		i[0] += 1;
	}
}

void	check_width(const char *str, t_flags *flags, int *i)
{
	char nmb[100];

	ft_grep_first_number(str, i, nmb);
	flags->min_size = ft_atoi(nmb);
}

void	check_prec(const char *str, t_flags *flags, int *i)
{
	char pres[100];

	if (str[i[0]] == '.')
	{
		*i += 1;
		flags->optdot = 1;
		ft_grep_first_number(str, i, pres);
		flags->prec = ft_atoi(pres);
	}
}

void	check_form(const char *str, t_flags *flags, int *i)
{
	if (str[i[0]] == 'h' || str[i[0]] == 'l' \
		|| str[i[0]] == 'j' || str[i[0]] == 'z')
	{
		flags->formf = str[i[0]];
		i[0] += 1;
		if (str[i[0]] == 'h' || str[i[0]] == 'l')
		{
			flags->formt = str[i[0]];
			*i += 1;
		}
		else
			flags->formt = '\0';
	}
	else
		flags->formf = '\0';
}

void	check_type(const char *str, t_flags *flags, int *i)
{
	if (type_cmp(str[i[0]]))
	{
		flags->type = str[i[0]];
		i[0] += 1;
	}
	else
		flags->type = '\0';
}
