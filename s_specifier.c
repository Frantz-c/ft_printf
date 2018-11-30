/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 19:10:56 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 21:13:26 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print padding if width > strlen(s)
*/
/*
static int		print_str_padding(const char *s, t_opt *o, int len, int rem)
{
	char		fill;
	int			ret;

	if (o->flag & MINUS)
	{
		ret = write(1, s, len) + rem;
		while (rem--)
			write(1, " ", 1);
		return (ret);
	}
	fill = (o->flag & ZERO) ? '0' : ' ';
	ret = rem;
	while (rem--)
		write(1, &fill, 1);
	return (ret + write(1, s, len));
}

inline int		s_specifier(const char *s, t_opt *o)
{
	const char	*null = "(null)";
	int			len;

	if (!s)
		s = null;
	len = ft_strnlen(s, o->precision > -1 ? o->precision : INTMAX);
	if (o->width > len)
		return (print_str_padding(s, o, len, o->width - len));
	return (write(1, s, len));
}
*/
extern int		s_specifier(const char *s, t_opt *o)
{
	const char	*null = "(null)";
	int			len;
	int			ret;

	if (!s)
		s = null;
	len = ft_strnlen(s, o->precision > -1 ? o->precision : INTMAX);
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
		o->cast = (o->flag & ZERO) ? '0' : ' ';
		ret = o->width;
		while (o->width--)
			write(1, &o->cast, 1);
		return (ret + write(1, s, len));

	}
	return (write(1, s, len));
}
