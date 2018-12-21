/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmaj_specifier.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 14:41:53 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:36:21 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

int		cmaj_spe(wchar_t c, t_opt *o)
{
	char	utf8[5];
	int		len;
	int		ret;

	len = unicode_to_utf8(c, utf8);
	if (o->width > len)
	{
		o->width -= len;
		if (o->flag & MINUS)
		{
			ret = write(1, utf8, len) + o->width;
			while (o->width--)
				write(1, " ", 1);
			return (ret);
		}
		o->length = (o->flag & ZERO) ? '0' : ' ';
		ret = o->width;
		while (o->width--)
			write(1, &o->length, 1);
		return (ret + write(1, utf8, len));
	}
	return (write(1, utf8, len));
}
