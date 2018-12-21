/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lf_specifier_functions.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 19:09:21 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 19:04:33 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "ulong128.h"
#include "numeric_str_op.h"

extern t_ulong	get_integer_part(t_ulong n, t_ulong128 *integer,
									t_uint exp, t_ulong curs)
{
	t_ulong		curs2;

	integer->lo |= (exp < 64) ? 1UL << exp-- : integer->lo;
	if (exp > 63)
	{
		exp -= 64;
		curs2 = 1UL << exp;
		integer->hi |= curs2;
		while (curs2 >>= 1)
		{
			if (n & curs)
				integer->hi |= curs2;
			curs >>= 1;
		}
		exp = 63;
	}
	curs2 = 1UL << exp;
	while (curs2)
	{
		if (n & curs)
			integer->lo |= curs2;
		curs >>= 1;
		curs2 >>= 1;
	}
	return (curs);
}

extern void		get_decimal_part(t_ulong n, t_ulong128 *decimal,
									t_ulong curs)
{
	t_ulong128		x;

	ulong128_assign(&x, "50000000000000000000000000000000000000");
	while (curs)
	{
		if (n & curs)
			ulong128_add(decimal, &x);
		if (!x.hi && !x.lo)
			break ;
		ulong128_shr(&x);
		curs >>= 1;
	}
}

extern int		get_zero_decimal_part(t_ulong n, t_ulong128 *integer,
										t_ulong128 *decimal, t_uint n_loop)
{
	t_ulong128	x;
	t_ulong		curs;

	ulong128_assign(&x, "50000000000000000000000000000000000000");
	while (n_loop--)
		ulong128_shr(&x);
	ulong128_add(decimal, &x);
	ulong128_shr(&x);
	curs = 0x4000000000000000UL;
	while (curs)
	{
		if (n & curs)
			ulong128_add(decimal, &x);
		if (!x.hi && !x.lo)
			break ;
		ulong128_shr(&x);
		curs >>= 1;
	}
	integer->lo = 0;
	integer->hi = 0;
	return (0);
}

static int		ft_mod10(long double n)
{
	long double	power;

	power = 10;
	while (n > power * 2)
		power *= 2;
	while (n >= 10)
	{
		if (n > power)
			n -= power;
		power /= 2;
	}
	return (n);
}

extern int		to_big_long_double(long double n, t_opt *o, int sign)
{
	char	buffer[5000];
	int		digit;
	int		digit_val;

	if (o->precision > 0)
	{
		digit = 4998 - o->precision - 1;
		buffer[4999 - o->precision - 1] = '.';
		while (o->precision)
		{
			buffer[4999 - o->precision] = '0';
			o->precision -= 1;
		}
	}
	else
		digit = 4998;
	buffer[4999] = '\0';
	while (n >= 1)
	{
		digit_val = ft_mod10(n);
		buffer[digit] = digit_val + 48;
		digit--;
		n /= 10;
	}
	return (print_number_with_options(buffer + digit + 1, o, sign));
}
