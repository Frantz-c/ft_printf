/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 20:58:58 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:47:10 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static t_longword	ft_repeat_c(int c)
{
	t_longword repeated_c;

	repeated_c = ((t_byte)c | (t_byte)c << 8);
	repeated_c |= repeated_c << 16;
	repeated_c |= repeated_c << 32;
	return (repeated_c);
}

static void			*get_chr(t_byte *ptr, t_byte c)
{
	if (*ptr == c)
		return ((void *)ptr);
	if (ptr[1] == c)
		return ((void *)ptr + 1);
	if (ptr[2] == c)
		return ((void *)ptr + 2);
	if (ptr[3] == c)
		return ((void *)ptr + 3);
	if (ptr[4] == c)
		return ((void *)ptr + 4);
	if (ptr[5] == c)
		return ((void *)ptr + 5);
	if (ptr[6] == c)
		return ((void *)ptr + 6);
	if (ptr[7] == c)
		return ((void *)ptr + 7);
	return (NULL);
}

extern inline void	*ft_memchr(const void *str, int c, size_t n)
{
	const t_longword	black_hole = 0x8080808080808080L;
	const t_longword	repeat_one = 0x0101010101010101L;
	const t_longword	c64 = ft_repeat_c(c);
	t_longword			word_content;

	if (!n)
		return (NULL);
	while (n > 0 && ((t_longword)str % sizeof(t_longword)) != 0)
	{
		if (*((t_byte *)str) == (t_byte)c)
			return ((void *)str);
		str += 1;
		n -= 1;
	}
	while (n >= 8 && (word_content = *(t_longword *)str ^ c64))
	{
		if (((word_content - repeat_one) & ~(word_content) & black_hole) != 0)
			return (get_chr((t_byte *)str, (t_byte)c));
		n -= 8;
		str += 8;
	}
	while (n--)
		if (*((t_byte *)str++) == (t_byte)c)
			return ((void *)str - 1);
	return (NULL);
}
