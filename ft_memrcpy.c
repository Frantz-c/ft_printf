/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memrcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 11:25:33 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 21:45:23 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		memcpy_not_same_align(t_longword dstp, t_longword srcp,
									size_t len, const t_longword shift)
{
	t_longword			merge;
	const size_t		shr = shift * 8;
	const size_t		shl = (8 - shift) * 8;

	srcp -= shift;
	while (1)
	{
		merge = *(t_longword *)srcp >> shr |
				*((t_longword *)srcp + 1) << shl;
		*(t_longword *)dstp = merge;
		len -= 8;
		if (len < 8)
			break ;
		dstp -= 8;
		srcp -= 8;
	}
	srcp += shift;
	while (len)
	{
		*(t_byte *)(--dstp) = *(t_byte *)(--srcp);
		len -= 1;
	}
}

static void		memcpy_same_alignement(t_longword dstp, t_longword srcp,
								size_t len)
{
	while (1)
	{
		*(t_longword *)dstp = *(t_longword *)srcp;
		len -= 8;
		if (len < 8)
			break ;
		dstp -= 8;
		srcp -= 8;
	}
	while (len)
	{
		dstp -= 1;
		srcp -= 1;
		*(t_byte *)dstp = *(t_byte *)srcp;
		len -= 1;
	}
}

static void		memcpy_no_alignement(t_byte *dst, t_byte *src, size_t len)
{
	while (len)
	{
		dst -= 1;
		src -= 1;
		*dst = *src;
		len -= 1;
	}
}

void			*ft_memrcpy(void *dst, const void *src, size_t len)
{
	t_longword	srcp;
	t_longword	dstp;

	if (len)
	{
		dstp = (t_longword)dst + len;
		srcp = (t_longword)src + len;
		while (dstp % 8)
		{
			*((t_byte *)--dstp) = *((t_byte *)--srcp);
			if (!--len)
				return (dst);
		}
		if (len > 7)
		{
			if (srcp % 8 == 0)
				memcpy_same_alignement(dstp - 8, srcp - 8, len);
			else
				memcpy_not_same_align(dstp - 8, srcp - 8, len, srcp % 8);
		}
		else
			memcpy_no_alignement((t_byte *)dstp, (t_byte *)srcp, len);
	}
	return (dst);
}
