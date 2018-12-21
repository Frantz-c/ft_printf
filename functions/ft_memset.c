/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 21:36:00 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:28:55 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static t_longword			get_repeat_c(int c)
{
	t_longword repeat_c;

	repeat_c = (t_byte)c | (t_byte)c << 8;
	repeat_c |= repeat_c << 16;
	repeat_c |= repeat_c << 32;
	return (repeat_c);
}

extern inline void			*ft_memset(void *s, int c, size_t n)
{
	t_longword	repeat_c;
	t_byte		*ptr;

	if (n)
	{
		ptr = s;
		while (n && (t_longword)ptr % 8 != 0)
		{
			*(ptr++) = (t_byte)c;
			n--;
		}
		if (n >= 8)
		{
			repeat_c = get_repeat_c(c);
			while ((*(t_longword *)ptr = repeat_c) &&
					(ptr += 8) && (n -= 8) >= 8)
				;
		}
		while (n)
		{
			*(ptr++) = (t_byte)c;
			--n;
		}
	}
	return (s);
}
