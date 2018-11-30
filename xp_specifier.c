/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_puthexa.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 16:57:58 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 21:21:42 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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

	if (o->length & LEN_HH)
		n = (t_byte)n;
	else if (o->length & LEN_H)
		n = (t_ushort)n;
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

extern inline int	p_specifier(t_ullong n, t_opt *o)
{
	o->length = 0;
	o->flag = SHARP;
	return (xxx_specifier(n, o, 32));
}

extern inline int	x_specifier(t_ullong n, t_opt *o)
{
	printf("XXXX = %llu\n", n);
	return (xxx_specifier(n, o, 32));
}

extern inline int	xmaj_specifier(t_ullong n, t_opt *o)
{
	return (xxx_specifier(n, o, 0));
}
