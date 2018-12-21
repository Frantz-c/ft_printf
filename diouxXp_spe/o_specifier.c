/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   o_specifier.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 18:08:03 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 09:47:46 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

extern int		o_spe(t_ullong n, t_opt *o)
{
	char		*p;
	char		buf[23];

	o->flag &= 0x1a;
	if (n == 0 && o->precision == 0)
	{
		if (o->flag & SHARP)
			return (print_number_with_options("0", o, 0));
		return (print_number_with_options("", o, 0));
	}
	p = buf + 22;
	*p = '\0';
	while (1)
	{
		*(--p) = (n % 8) + 48;
		if (!(n /= 8))
			break ;
	}
	return (print_number_with_options(p, o, (o->flag & SHARP) ? '0' : 0));
}
