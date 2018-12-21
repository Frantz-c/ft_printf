/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   w_specifier.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 20:40:54 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 19:01:49 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

static int			ld_to_binary_hi(t_ulong n, char *buf, t_opt *o)
{
	const char	*constptr = buf;
	t_ulong		curs;

	curs = 0x8000UL;
	if (o->flag & SHARP)
		buf = ft_strncpy(buf, "SIGN ", 5) + 5;
	while (curs)
	{
		*(buf++) = (curs & n) ? '1' : '0';
		if (curs & 0x101UL && o->flag & SPACE)
			*(buf++) = ' ';
		if (curs & 0x8000UL && o->flag & SHARP)
			buf = ft_strncpy(buf, "  EXP ", 7) + 7;
		curs >>= 1;
	}
	return (buf - constptr);
}

static int			ld_to_binary_lo(t_ulong n, char *buf, t_opt *o)
{
	const char	*constptr = buf;
	t_ulong		curs;

	curs = 0x8000000000000000UL;
	if (o->flag & SHARP)
		buf = ft_strncpy(buf, "  MANT ", 7) + 7;
	while (curs)
	{
		*(buf++) = (curs & n) ? '1' : '0';
		if (curs & 0x0101010101010100UL && o->flag & SPACE)
			*(buf++) = ' ';
		curs >>= 1;
	}
	*buf = '\0';
	return (buf - constptr);
}

extern inline int	lv_spe(long double n, t_opt *o)
{
	char		buf[200];
	int			len;

	len = ld_to_binary_hi(*(t_ulong*)((void*)&n + 8), buf, o);
	len += ld_to_binary_lo(*(t_ulong*)((void*)&n), buf + len, o);
	return (write(1, buf, len));
}
