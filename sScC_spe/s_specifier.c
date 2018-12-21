/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 19:10:56 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:36:32 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

extern inline int		s_spe(const char *s, t_opt *o)
{
	const char	*null = "(null)";
	int			len;
	int			ret;

	if (!s)
		s = null;
	len = ft_strnlen(s, o->precision > -1 ? o->precision : INTMAX);
	return (print_string_with_options(s, o, len));
	if (o->width > len)
	{
		o->width -= len;
		if (o->flag & MINUS)
		{
			ret = write(1, s, len) + o->width;
			while (o->width--)
				write(1, " ", 1);
			return (ret);
		}
		o->length = (o->flag & ZERO) ? '0' : ' ';
		ret = o->width;
		while (o->width--)
			write(1, &o->length, 1);
		return (ret + write(1, s, len));
	}
	return (write(1, s, len));
}
