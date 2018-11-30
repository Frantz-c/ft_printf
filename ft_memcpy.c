/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2016/10/17 15:51:59 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/23 18:52:02 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		memcpy_not_same_alignement(t_longword dstp, t_longword srcp,
											size_t len, const t_longword shift)
{
	t_longword			merge;
	const size_t		shr = shift * 8;
	const size_t		shl = (8 - shift) * 8;

	srcp -= shift;
	while (FT_INFINITE)
	{
		merge = *(t_longword *)srcp >> shr | *((t_longword *)(srcp + 8)) << shl;
		*(t_longword *)dstp = merge;
		dstp += 8;
		srcp += 8;
		len -= 8;
		if (len < 8)
			break ;
	}
	srcp += shift;
	while (len)
	{
		*(t_byte *)dstp = *(t_byte *)srcp;
		dstp += 1;
		srcp += 1;
		len -= 1;
	}
}

static void		memcpy_same_alignement(t_longword dstp, t_longword srcp,
										size_t len)
{
	while (FT_INFINITE)
	{
		*(t_longword *)dstp = *(t_longword *)srcp;
		dstp += 8;
		srcp += 8;
		len -= 8;
		if (len < 8)
			break ;
	}
	while (len)
	{
		*(t_byte *)dstp = *(t_byte *)srcp;
		dstp += 1;
		srcp += 1;
		len -= 1;
	}
}

static void		memcpy_no_alignement(t_byte *dst, t_byte *src, size_t len)
{
	while (FT_INFINITE)
	{
		*dst = *src;
		if (!--len)
			break ;
		dst += 1;
		src += 1;
	}
}

inline void		*ft_memcpy(void *dst, const void *src, size_t len)
{
	t_longword	srcp;
	t_longword	dstp;

	if (len)
	{
		dstp = (t_longword)dst;
		srcp = (t_longword)src;
		while (dstp % 8)
		{
			*((t_byte *)dstp++) = *((t_byte *)srcp++);
			if (!--len)
				return (dst);
		}
		if (len > 7)
		{
			if (srcp % 8 == 0)
				memcpy_same_alignement(dstp, srcp, len);
			else
				memcpy_not_same_alignement(dstp, srcp, len, srcp % 8);
		}
		else
			memcpy_no_alignement((t_byte *)dstp, (t_byte *)srcp, len);
	}
	return (dst);
}
