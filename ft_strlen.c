/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 11:03:43 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 18:21:17 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int				which_is_zero(const t_byte *p, const t_byte *start)
{
	if (*p == '\0')
		return (p - start);
	if (p[1] == '\0')
		return ((p - start) + 1);
	if (p[2] == '\0')
		return ((p - start) + 2);
	if (p[3] == '\0')
		return ((p - start) + 3);
	if (p[4] == '\0')
		return ((p - start) + 4);
	if (p[5] == '\0')
		return ((p - start) + 5);
	if (p[6] == '\0')
		return ((p - start) + 6);
	return ((p - start) + 7);
}

extern inline int		ft_strlen(const char *str)
{
	const t_byte			*ptr;
	const t_longword		*word_ptr;
	t_longword				word;

	ptr = (const t_byte *)str;
	while (((t_longword)ptr & 7) != 0)
	{
		if (!*ptr)
			return (ptr - (const t_byte *)str);
		ptr++;
	}
	word_ptr = (t_longword *)ptr;
	while (1)
	{
		word = *word_ptr;
		if (((word - 0x0101010101010101UL) & ~word & 0x8080808080808080UL))
			break ;
		word_ptr++;
	}
	return (which_is_zero((const t_byte *)word_ptr, (const t_byte *)str));
}
