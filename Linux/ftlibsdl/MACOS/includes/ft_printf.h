/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 10:19:59 by avallete          #+#    #+#             */
/*   Updated: 2015/01/16 16:40:37 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <libft.h>
# include <limits.h>
# include <stdarg.h>
# define HEXMAJ ("0123456789ABCDEF")
# define HEXMIN ("0123456789abcdef")
# define OXMAJ	("0X000000000000")
# define OXMIN	("0x000000000000")

typedef	struct	s_flags
{
	char		optmin;
	char		optplus;
	char		optzero;
	char		optsharp;
	char		optspace;
	char		optdot;
	char		formf;
	char		formt;
	int			min_size;
	int			prec;
	int			size;
	char		type;
}				t_flags;

/*
** ----------
** Misc functions
** ----------
*/

int				check_exstr(const char *str);
char			*ft_grep_first_number(const char *str, int *i, char *result);
int				type_cmp(const char c);
void			fill_it(t_flags *flags, int size);
void			print_plus(t_flags *flags, int *i, int c, int *size);
int				ft_wstrlen(wchar_t *str);
int				ft_wnstrlen(wchar_t *str, int n);
int				ft_putwnstr(wchar_t *str, int n);
char			ft_wcharlen(wchar_t c);
int				ft_putwstr(wchar_t *str);
void			ft_linttoct(unsigned long long int nb, char *str);
int				ft_longnbrlen(long int nb);
void			ft_putlongnbr(long int nb);

/*
** ----------
** Check_flags functions
** Functions assign value in t_flags with boolean value for each option.
** ----------
*/

void			check_flg(const char *str, t_flags *flags, int *i);
void			check_width(const char *str, t_flags *flags, int *i);
void			check_prec(const char *str, t_flags *flags, int *i);
void			check_form(const char *str, t_flags *flags, int *i);
void			check_type(const char *str, t_flags *flags, int *i);

/*
** ----------
** Ft_argument functions
** Functions call check_flags and convert function for each argument.
** ----------
*/

int				found_flags(const char *str, va_list list);
void			ft_arg_sort(const char *str, va_list list, int *i);
void			init_flags(const char *str, t_flags *flags, int *i);
void			ft_type_sort(const char *str, t_flags *flags, \
														va_list list, int *i);

/*
** ----------
** Converter function
** ----------
*/
void			arg_is_mod(t_flags *flags, int *i);

void			arg_is_string(t_flags *flags, va_list list, int *i);
void			print_string(t_flags *flags, va_list list, int *i);

void			arg_is_char(t_flags *flags, va_list list, int *i);
void			print_char(t_flags *flags, va_list list, int *i);

void			arg_is_int(t_flags *flags, va_list list, int *i);
void			print_int(t_flags *flags, va_list list, int *i);
int				print_int_fill(t_flags *flags, int *i, int c);
void			print_int_opt(t_flags *flags, int c, int size, int *i);
void			print_int_rev(t_flags *flags, int *i, int size, int c);
void			print_no_min(t_flags *flags, int *i, int c);
void			print_plus(t_flags *flags, int *i, int c, int *size);
void			fill_it(t_flags *flags, int size);
void			cast_int(int *c, va_list list, t_flags *flags);

void			ft_putlongnbr(long int nb);
int				ft_longnbrlen(long int nb);
void			print_longint_opt(t_flags *flags, long int l, int size, int *i);
int				print_lint_fill(t_flags *flags, int *i, long int l);
void			print_longi(t_flags *flags, va_list list, int *i);
void			arg_is_longi(t_flags *flags, va_list list, int *i);

void			ft_linttohexa(unsigned long int nb, char *str, char *hex);
void			arg_is_ptr(t_flags *flags, va_list list, int *i);
void			print_ptr(t_flags *flags, va_list list, int *i);
void			print_rev_ptr(t_flags *flags, va_list list, int *i);
void			cast_hexa(unsigned long long int *c, \
												va_list list, t_flags *flags);
void			ft_inttohexa(unsigned long long int nb, char *str, char *hex);
void			arg_is_x(t_flags *flags, va_list list, int *i);
void			print_x(t_flags *flags, va_list list, int *i);
void			arg_is_octal(t_flags *flags, va_list list, int *i);
void			print_octal(t_flags *flags, va_list list, int *i);
void			ft_linttoct(unsigned long long int nb, char *str);
void			cast_octal(unsigned long long int *c, \
												va_list list, t_flags *flags);
int				max_ul(t_flags *flags);
int				max_l(t_flags *flags);
int				max_uol(t_flags *flags);
int				max_value(t_flags *flags, unsigned long long nb);

void			ft_putlnbr(unsigned long long int nbr);
int				ft_lnbrlen(unsigned long long int nbr);
void			print_unsigned(t_flags *flags, va_list list, int *i);
void			cast_unsigned(unsigned long long int *c, \
												va_list list, t_flags *flags);
void			arg_is_unsigned(t_flags *flags, va_list list, int *i);
void			arg_is_wchar(t_flags *flags, va_list list, int *i);
void			print_wchar(va_list list, int *i);
char			ft_putwchar(wchar_t c);
void			ft_putnchar(unsigned char *f, int size);
void			init_wchar(unsigned char *f, wchar_t c, int mode);
int				ft_putwstr(wchar_t *str);
void			print_wstr(t_flags *flags, va_list list, int *i);
void			arg_is_wstr(t_flags *flags, va_list list, int *i);
void			init_wchar(unsigned char *f, wchar_t c, int mode);
void			ft_putnchar(unsigned char *f, int size);
char			ft_print_w(unsigned char *f, unsigned int e, wchar_t c);
char			ft_putwchar(wchar_t c);

/*
** ----------
** Ft_printf function
** The main function, check if str exist, launch args sort if % found.
** Else function do putstr and return (strlen)
** ----------
*/

int				ft_printf(const char *format, ...);
#endif
