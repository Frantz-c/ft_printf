/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_puthexa.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 16:57:58 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 09:47:35 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

static char			hexa(unsigned char c, int interval)
{
	if (c > 9)
		return (c + 55 + interval);
	return (c + 48);
}

static inline int	xxx_specifier(t_ullong n, t_opt *o, int interval)
{
	char		*p;
	char		buf[22];
	int			sign;

	o->flag &= 0x1a;
	if (n == 0 && o->precision == 0)
		return (print_number_with_options("", o, 0));
	if (n && o->flag & SHARP)
		sign = 'X' + interval;
	else
		sign = 0;
	p = buf + 21;
	*p = '\0';
	while (1)
	{
		*(--p) = hexa(n % 16, interval);
		if (!(n /= 16))
			break ;
	}
	return (print_number_with_options(p, o, sign));
}

extern inline int	p_spe(t_ullong n, t_opt *o)
{
	if (n == 0)
	{
		if (o->precision == 0)
			return (print_number_with_options("", o, 123456789));
		return (print_number_with_options("0", o, 123456789));
	}
	o->flag = SHARP;
	return (xxx_specifier(n, o, 32));
}

extern inline int	x_spe(t_ullong n, t_opt *o)
{
	return (xxx_specifier(n, o, 32));
}

extern inline int	xmaj_spe(t_ullong n, t_opt *o)
{
	return (xxx_specifier(n, o, 0));
}
