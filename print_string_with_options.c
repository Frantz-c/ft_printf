/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_string_with_options.c                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 13:57:59 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 14:14:32 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

extern int		print_string_with_options(const char *s, t_opt *o, int len)
{
	int			ret;

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
