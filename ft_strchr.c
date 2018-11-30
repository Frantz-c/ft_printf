/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 17:43:28 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 21:45:36 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static t_longword	get_repeat_c(t_byte c)
{
	t_longword cc;

	cc = c | c << 8;
	cc |= cc << 16;
	cc |= cc << 32;
	return (cc);
}

static char			*get_chr_nullbyte(const t_byte *s, t_byte c)
{
	if (*s == c)
		return ((char *)s);
	if (*s == '\0')
		return (NULL);
	if (s[1] == c)
		return ((char *)s + 1);
	if (s[1] == '\0')
		return (NULL);
	if (s[2] == c)
		return ((char *)s + 2);
	if (s[2] == '\0')
		return (NULL);
	if (s[3] == c)
		return ((char *)s + 3);
	if (s[3] == '\0')
		return (NULL);
	if (s[4] == c)
		return ((char *)s + 4);
	if (s[4] == '\0')
		return (NULL);
	if (s[5] == c)
		return ((char *)s + 5);
	if (s[5] == '\0')
		return (NULL);
	return (get_chr_nullbyte(s + 6, c));
}

static char			*ft_strchr_2(t_longword ptr, t_byte c)
{
	const t_longword	repeat_c = get_repeat_c(c);
	const t_longword	repeat_one = 0x0101010101010101UL;
	const t_longword	black_hole = 0x8080808080808080UL;
	t_longword			has_null;
	t_longword			has_char;

	while (1)
	{
		has_null = *(t_longword *)ptr;
		has_char = has_null ^ repeat_c;
		if ((((has_null - repeat_one) & ~has_null & black_hole) != 0) ||
			(((has_char - repeat_one) & ~has_char & black_hole) != 0))
		{
			return (get_chr_nullbyte((const t_byte *)ptr, c));
		}
		ptr += 8;
	}
	return (NULL);
}

extern inline char	*ft_strchr(const char *s, int int_c)
{
	t_byte c;

	c = (t_byte)int_c;
	while ((t_longword)s % 8 != 0)
	{
		if (*s == c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (ft_strchr_2((t_longword)s, c));
}
