/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   v_specifier_w.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 22:26:26 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 21:01:24 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static t_ullong		set_masks(t_ullong *man_space, t_ullong *exp_space, int flag)
{
	t_ullong	space;

	space = 0x0ULL;
	*exp_space = 0x0ULL;
	*man_space = 0x0ULL;
	if (flag & SHARP)
	{
		*exp_space = 0x8000000000000000ULL;
		*man_space = 0x0010000000000000ULL;
		if (flag & SPACE)
			space = 0x0101010101010100ULL;
	}
	return (space);
}

static size_t		dtoa(t_ullong n, char *p, int flag)
{
	t_ullong	curs;
	t_ullong	exp_space;
	t_ullong	man_space;
	t_ullong	space;
	char		*start;

	start = p;
	space = set_masks(&man_space, &exp_space, flag);
	curs = 1ULL << 63;
	if (flag & SHARP)
		p = ft_strncpy(p, "SIGN ", 5) + 5;
	while (curs)
	{
		*(p++) = (curs & n) ? '1' : '0';
		if (curs & space)
			*(p++) = ' ';
		if (curs & exp_space)
			p = ft_strncpy(p, "  EXP  ", 6) + 6;
		else if (curs & man_space)
			p = ft_strncpy(p, "  MANT ", 7) + 7;
		curs >>= 1;
	}
	*p = '\0';
	return (p - start);
}

extern inline int	v_specifier(double n, t_opt *o)
{
	char			buf[136];
	size_t			size;

	size = dtoa(*(t_ullong*)&n, buf, o->flag);
	return (write(1, buf, size));
}
