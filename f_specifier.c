/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   f_specifier.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 19:50:17 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 12:26:45 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "is_nan.h"
#include "ft_printf.h"

static t_ulong		get_integer_part(t_ulong n, t_ulong *integer,
									t_ulong curs, t_ulong curs2)
{
	while (curs2)
	{
		if (n & curs)
			*integer |= curs2;
		curs >>= 1;
		curs2 >>= 1;
	}
	return (curs);
}

static void			get_decimal_part(t_ulong n, t_ulong *decimal, t_ulong curs)
{
	t_ulong		x;

	x = 5000000000000000000UL;
	while (curs)
	{
		if (n & curs)
			*decimal += x;
		if (x == 0)
			break ;
		x /= 2;
		curs >>= 1;
	}
}

static inline int	get_zero_decimal_part(t_ulong n, t_ulong *integer,
										t_ulong *decimal, t_uint n_loop)
{
	t_ulong	x;
	t_ulong	curs;

	x = 5000000000000000000UL;
	while (n_loop--)
		x /= 2;
	*decimal = x;
	x /= 2;
	curs = 1UL << 51;
	while (curs)
	{
		if (n & curs)
			*decimal += x;
		if (x == 0)
			break ;
		x /= 2;
		curs >>= 1;
	}
	*integer = 0;
	return (0);
}

static int			get_float(t_ulong n, t_ulong *integer, t_ulong *decimal,
							t_ulong curs)
{
	t_uint	expl;
	t_ulong	curs2;

	*integer = 0;
	*decimal = 0;
	expl = 0;
	curs2 = 0x400UL; //(1UL << 10)
	while (curs2)
	{
		if (n & curs)
			expl |= curs2;
		curs >>= 1;
		curs2 >>= 1;
	}
	if (expl == 0x7ffU)
		return (-1);
	if (expl < 1023)
		return (get_zero_decimal_part(n, integer, decimal, 1022 - expl));
	expl -= 1023;
	*integer |= 1UL << expl;
	curs2 = (expl) ? 1UL << (expl - 1) : 0;
	curs = get_integer_part(n, integer, curs, curs2);
	get_decimal_part(n, decimal, curs);
	return (0);
}

static void			round_number_integer(t_ulong decimal, char *dc, char *p,
										t_ulong *integer)
{
	ultoa_buf(decimal, p);
	if (*dc > '4')
		(*integer)++;
	*dc = '\0';
}

static void			round_number_decimal(t_ulong decimal, char *p, char *dc,
										t_opt *o)
{
	ultoa_buf(decimal, p);
	dc[o->precision] = '\0';
}

static inline int	ascii_double(t_ulong n, t_opt *o, char *in, char *dc)
{
	t_ulong		decimal;
	t_ulong		integer;
	int			nzero;
	char		*p;

	if (get_float(n, &integer, &decimal, 0x4000000000000000UL) == -1)
		return (is_inf_or_nan_d(n, in));
	if (o->precision == -1)
		o->precision = 6;
	else if (o->precision > 19) // A supprimer
		o->precision = 19;
	p = dc;
	nzero = get_left_zero_count(decimal);
	while (nzero--)
		*(p++) = '0';
	if (o->precision == 0)
		round_number_integer(decimal, dc, p, &integer);
	else
		round_number_decimal(
			(decimal += ft_ten_powul(19 - o->precision + nzero) * 5), p, dc, o);
	nzero = ultoa_buf(integer, in);
	in[nzero] = (o->precision) ? '.' : '\0';
	in[nzero + 1] = '\0';
	return (n & 0x8000000000000000UL);
}

extern inline int	f_specifier(double n, t_opt *o)
{
	char	buf[48];
	char	*integer;
	char	*decimal;
	int		sign;

	integer = buf;
	decimal = buf + 24;
	if ((sign = ascii_double(*(t_ullong*)&n, o, integer, decimal)) > 1)
		return (print_number_with_options(integer, o, (sign == 4)));
	ft_strcat(integer, decimal);
	return (print_number_with_options(integer, o, sign));
}
