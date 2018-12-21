/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   f_specifier.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 19:50:17 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 12:47:38 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "numeric_str_op.h"

static int			is_inf_or_nan_d(t_ulong n, t_opt *o)
{
	char	buf[4];
	int		sign;

	if ((n & 0x7fffffffffffffffUL) == FT_INF64_P)
	{
		ft_strcpy(buf, "inf");
		sign = ((n & 0x8000000000000000UL) != 0);
	}
	else
	{
		ft_strcpy(buf, "nan");
		sign = 0;
	}
	o->precision = -1;
	return (print_number_with_options(buf, o, sign));
}

static double		ft_mod(double n, double m)
{
	double	power;

	power = m;
	while (n > power * 2)
		power *= 2;
	while (n >= m)
	{
		if (n >= power)
			n -= power;
		power /= 2;
	}
	return (n);
}

static void			set_integer_part(double n, char *buffer, int *digit)
{
	int		digit_val;

	while (n >= 1)
	{
		digit_val = ft_mod(n, 10);
		buffer[(*digit)--] = digit_val + 48;
		n /= 10;
	}
}

static int			to_big_double(double n, t_opt *o, int sign)
{
	char	buffer[5000];
	int		digit;
	double	d;

	buffer[4999] = '\0';
	digit = 4998;
	if (o->precision)
	{
		d = ft_mod(n, 1);
		digit -= o->precision++;
		while (o->precision)
		{
			buffer[4999 - (o->precision--)] = (char)(d * 10) + '0';
			d = ft_mod(d * 10, 1);
		}
		numeric_str_add(buffer + digit, "5");
		buffer[--digit] = '.';
		buffer[4998] = '\0';
		digit--;
	}
	else if (o->flag & SHARP)
		buffer[digit--] = '.';
	set_integer_part(n, buffer, &digit);
	return (print_number_with_options(buffer + digit + 1, o, sign));
}

extern inline int	f_spe(double n, t_opt *o)
{
	if (o->precision == -1)
		o->precision = 6;
	if ((*(t_ulong*)&n & 0x7ff0000000000000UL) == 0x7ff0000000000000UL)
		return (is_inf_or_nan_d(*(t_ulong*)&n, o));
	return (to_big_double(n, o, (*(t_ulong*)&n & 0x8000000000000000UL) != 0));
}
