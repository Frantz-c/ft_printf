/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   w_specifier.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 20:40:54 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 21:04:30 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ulong128.h"

static int	get_ulong128_longd_binary_str(t_ulong128 *n, char *buf)
{
	const char	*constptr = buf;
	t_ulong		curs;

	curs = 0x8000UL;
	buf = ft_strncpy(buf, "SIGN  ", 6) + 6;
	while (curs)
	{
		*(buf++) = (curs & n->hi) ? '1' : '0';
		if(curs & 0x101UL)
			*(buf++) = ' ';
		if (curs & 0x8000UL)
			buf = ft_strncpy(buf, " EXP  ", 7) + 7;
		curs >>= 1;
	}
	buf = ft_strncpy(buf, " MANT  ", 7) + 7;
	curs = 0x8000000000000000UL;
	while (curs)
	{
		*(buf++) = (curs & n->lo) ? '1' : '0';
		if(curs & 0x0101010101010100UL)
			*(buf++) = ' ';
		curs >>= 1;
	}
	*buf = '\0';
	return (buf - constptr);
}

extern int	w_specifier(long double n, t_opt *o)
{
	t_ulong128	f;
	char		buf[200];
	int			len;

	(void)o;
	f.hi = *(t_ulong*)((void*)&n);
	f.lo = *(t_ulong*)((void*)&n + 8);
	len = get_ulong128_longd_binary_str(&f, buf);
	return (write(1, buf, len));
}
