/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_specifier.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 17:53:58 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:34:28 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

static void			btoa(t_ullong n, char *p, size_t size, int space)
{
	t_ullong		curs;
	t_ullong		mask;

	mask = 0x0101010101010100ULL;
	if (sizeof(t_ullong) == 16)
		mask |= (0x0101010101010101ULL << 64);
	curs = 1ULL << ((size * 8) - 1);
	while (curs)
	{
		*(p++) = (curs & n) ? '1' : '0';
		if (space && (curs & mask))
			*(p++) = ' ';
		curs >>= 1;
	}
	*p = '\0';
}

extern inline int	b_spe(t_ullong n, t_opt *o)
{
	char			buf[136];
	size_t			size;

	if (o->length == L_LL)
		size = sizeof(t_ullong);
	else if (o->length == L_L)
		size = sizeof(t_ulong);
	else if (o->length == L_H)
		size = sizeof(t_ushort);
	else if (o->length == L_HH)
		size = 1;
	else if (o->length == L_Z)
		size = sizeof(size_t);
	else if (o->length == L_J)
		size = sizeof(uintmax_t);
	else
		size = sizeof(t_uint);
	btoa(n, buf, size, o->flag & SPACE);
	o->flag &= ~(SPACE);
	return (print_number_with_options(buf, o, o->flag & SHARP ? 'b' : 0));
}
