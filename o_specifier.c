/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   o_specifier.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 18:08:03 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 11:16:23 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

extern int		o_specifier(t_ullong n, t_opt *o)
{
	char		*p;
	char		buf[22];

	if (!(o->length & LEN_L) && !(o->length & LEN_LL))
	{
		if (o->length & LEN_HH)
			n = (t_byte)n;
		else if (o->length & LEN_H)
			n = (t_ushort)n;
	}
	p = buf + 21;
	*p = '\0';
	while (n)
	{
		*(--p) = (n % 8) + 48;
		n /= 8;
	}
	if (ft_strlen(p) < o->precision)
		o->flag ^= SHARP;
	return (print_number_with_options(p, o, o->flag & SHARP ? '0' : 0));
}
