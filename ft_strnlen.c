/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnlen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:43:09 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/25 18:39:59 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int			get_nullbyte(const t_byte *s, const t_byte *end,
								const t_byte *start)
{
	const t_longword	end_byte = (t_longword)(end - s);

	if (s[0] == 0)
		return (s - start);
	if (s[1] == 0 || 1 == end_byte)
		return (s - start + 1);
	if (s[2] == 0 || 2 == end_byte)
		return (s - start + 2);
	if (s[3] == 0 || 3 == end_byte)
		return (s - start + 3);
	if (s[4] == 0 || 4 == end_byte)
		return (s - start + 4);
	if (s[5] == 0 || 5 == end_byte)
		return (s - start + 5);
	if (s[6] == 0 || 6 == end_byte)
		return (s - start + 6);
	return (s - start + 7);
}

static inline int	ft_strnlen_align(t_longword pstr,
									const t_longword end,
									const t_longword start)
{
	t_longword	val;

	while (pstr < end)
	{
		val = *(t_longword *)pstr;
		if (((val - 0x101010101010101UL) & ~val & 0x8080808080808080) != 0)
		{
			return (get_nullbyte((const t_byte *)pstr,
								(const t_byte *)end,
								(const t_byte *)start));
		}
		pstr += 8;
	}
	return (end - start);
}

extern inline int	ft_strnlen(const char *str, t_uint max)
{
	t_longword		pstr;
	t_longword		end;

	if (max == 0)
		return (0);
	end = (t_longword)str + max;
	if (end < (t_longword)str)
		end = ~0UL;
	pstr = (t_longword)str;
	while (pstr % 8 != 0)
	{
		if (*(t_byte *)pstr != 0 && pstr < end)
			pstr += 1;
		else
			return (pstr - (t_longword)str);
	}
	return (ft_strnlen_align(pstr, end, (t_longword)str));
}
