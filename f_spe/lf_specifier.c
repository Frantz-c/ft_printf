/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lf_specifier.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/28 11:00:32 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 19:03:39 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "is_nan.h"
#include "ulong128.h"
#include "numeric_str_op.h"
#include "lf_specifier_functions.h"

static int			get_float(t_ulong128 *n, t_ulong128 *integer,
							t_ulong128 *decimal, t_ulong curs)
{
	t_uint	expl;

	integer->lo = 0;
	integer->hi = 0;
	decimal->lo = 0;
	decimal->hi = 0;
	expl = 0;
	while (curs)
	{
		if (n->hi & curs)
			expl |= curs;
		curs >>= 1;
	}
	if (expl == 0x7fff)
		return (-1);
	if (expl < 16383)
		return (get_zero_decimal_part(n->lo, integer, decimal, 16382 - expl));
	expl -= 16383;
	curs = get_integer_part(n->lo, integer, expl, 0x4000000000000000UL);
	get_decimal_part(n->lo, decimal, curs);
	return (0);
}

static char			*round_number(int precision, char *in, char *dc)
{
	char		round[41];
	int			nzero;

    puts("\e[1;34mROUND\e[0m");
	*round = '5';
	if (38 - precision > 0)
	{
		ft_memset(round + 1, '0', 37 - precision);
		round[38 - precision] = '\0';
	}
	else
		round[1] = '\0';
	nzero = 38 - ft_strlen(dc);
	while (nzero--)
		*(--dc) = '0';
	numeric_str_add(dc, round);
    ft_strcat(in, ".");
	return (dc);
}

static inline int	ascii_double(t_ulong128 *n, t_opt *o, char **in, char **dc)
{
	t_ulong128	decimal;
	t_ulong128	integer;

	if (get_float(n, &integer, &decimal, 0x4000UL) == -1)
	{
		o->precision = -1;
		return (is_inf_or_nan_ld(n->hi & 0x8000UL, n->lo, *in));
	}
	if (o->precision == -1)
		o->precision = 6;
	*in = ulong128_to_ascii(*in, &integer, 47);
	*dc = ulong128_to_ascii(*dc, &decimal, 48);
	if (o->precision > 0)
		*dc = round_number(o->precision, *in, *dc);
    else
    {
        if (**dc > '5')
            *in -= numeric_str_add(*in, "1");
        if (o->flag & SHARP)
            ft_strcat(*in, ".");
    }
	(*dc)[o->precision] = '\0';
	o->precision = -1;
	return ((n->hi & 0x8000UL) != 0);
}

extern inline int	lf_spe(long double n, t_opt *o)
{
	char		buf[96];
	char		*decimal;
	char		*integer;
	int			sign;
	t_ulong128	f;

	f.hi = *(t_ulong*)((void*)&n + 8);
	f.lo = *(t_ulong*)((void*)&n);
	if (n > 1e38 || o->precision > 38)
	{
		if (o->precision == -1)
			o->precision = 6;
		if ((sign = is_inf_or_nan2(&f, (f.hi & 0x8000UL) != 0, buf)) > 1)
		{
			o->precision = -1;
			return (print_number_with_options(buf, o, (sign == 4)));
		}
		return (to_big_long_double(n, o, (f.hi & 0x8000UL) != 0));
	}
	decimal = buf + 48;
	integer = buf;
	if ((sign = ascii_double(&f, o, &integer, &decimal)) > 1)
		return (print_number_with_options(integer, o, (sign == 4)));
	ft_strcat(integer, decimal);
	return (print_number_with_options(integer, o, sign));
}
