/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   _=+/'''''''''\+=_                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: FCORDON <101@le-101.101>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 1992/02/24 01:46:29 by FCORDON      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 21:18:46 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int			is_specifier3(const char **c, t_opt *o, va_list ap)
{
	if (**c == 'w')
		return (w_specifier(va_arg(ap, long double), o));
	else if (**c == 'y')
		return (y_specifier(va_arg(ap, void*), o, c));
	return (-1);
}

static inline int	is_specifier2(const char **c, t_opt *o, va_list ap)
{
	if (**c == 's')
		return (s_specifier(va_arg(ap, char*), o));
	if (**c == 'f')
	{
		if (o->length & LEN_LF)
			return (lf_specifier(va_arg(ap, long double), o));
		return (f_specifier(va_arg(ap, double), o));
	}
	if (**c == 'v')
		return (v_specifier(va_arg(ap, double), o));
	if (**c == 'u')
	{
		if (o->length & LEN_LL)
			return (u_specifier(va_arg(ap, t_ullong), o));
		if (o->length & LEN_L)
			return (u_specifier(va_arg(ap, t_ulong), o));
		return (u_specifier(va_arg(ap, t_uint), o));
	}
	if (**c == 'c')
		return (c_specifier(va_arg(ap, int), o));
	return (is_specifier3(c, o, ap));
}

static inline int	call_function(const char **c, t_opt *o, va_list ap)
{
	if (**c == 'd' || **c == 'i')
	{
		if (o->length & LEN_LL)
			return (di_specifier(va_arg(ap, long long int), o));
		if (o->length & LEN_L)
			return (di_specifier(va_arg(ap, long int), o));
		return (di_specifier(va_arg(ap, int), o));
	}
	if (**c == 'x')
		return (x_specifier(va_arg(ap, t_ullong), o));
	if (**c == 'X')
		return (xmaj_specifier(va_arg(ap, t_ullong), o));
	if (**c == 'p')
		return (p_specifier((t_ullong)va_arg(ap, void*), o));
	if (**c == 'o')
		return (o_specifier(va_arg(ap, t_ullong), o));
	if (**c == 'b')
		return (b_specifier(va_arg(ap, long long int), o));
	return (is_specifier2(c, o, ap));
}

extern inline int	get_specifier(const char **s, t_opt *o, va_list ap)
{
	int		ret;

	while (**s)
	{
		if ((ret = call_function(s, o, ap)) > -1)
		{
			(*s)++;
			return (ret);
		}
		if (**s == '%')
		{
			(*s)++;
			o->precision = -1;
			return (print_number_with_options("%", o, 0));
		}
		(*s)++;
	}
	return (0);
}
