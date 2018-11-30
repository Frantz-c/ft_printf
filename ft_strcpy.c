/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 11:44:20 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 21:45:06 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		strcpy_no_alignement(t_byte *dst, t_byte *src)
{
	if ((*dst = *src) == 0)
		return ;
	if ((dst[1] = src[1]) == 0)
		return ;
	if ((dst[2] = src[2]) == 0)
		return ;
	if ((dst[3] = src[3]) == 0)
		return ;
	if ((dst[4] = src[4]) == 0)
		return ;
	if ((dst[5] = src[5]) == 0)
		return ;
	if ((dst[6] = src[6]) == 0)
		return ;
	dst[7] = src[7];
}

static inline void		strcpy_not_same_alignement(t_longword dstp, t_longword srcp,
											size_t shift)
{
	t_longword			merge;
	const size_t		shr = shift * 8;
	const size_t		shl = (8 - shift) * 8;
	const t_longword	repeat_one = 0x0101010101010101UL;
	const t_longword	black_hole = 0x8080808080808080UL;

	srcp -= shift;
	while (1)
	{
		merge = *(t_longword *)srcp >> shr | *((t_longword *)srcp + 1) << shl;
		if (((merge - repeat_one) & ~merge & black_hole) != 0)
		{
			strcpy_no_alignement((t_byte *)dstp, (t_byte *)(srcp + shift));
			return ;
		}
		*(t_longword *)dstp = merge;
		dstp += 8;
		srcp += 8;
	}
}

static inline void		strcpy_same_alignement(t_longword dstp, t_longword srcp)
{
	const t_longword	repeat_one = 0x0101010101010101UL;
	const t_longword	black_hole = 0x8080808080808080UL;
	t_longword			word;

	while (1)
	{
		word = *(t_longword *)srcp;
		if (((word - repeat_one) & ~word & black_hole) != 0)
		{
			strcpy_no_alignement((t_byte *)dstp, (t_byte *)srcp);
			return ;
		}
		*(t_longword *)dstp = *(t_longword *)srcp;
		dstp += 8;
		srcp += 8;
	}
}

inline char		*ft_strcpy(char *dst, const char *src)
{
	t_longword	srcp;
	t_longword	dstp;

	dstp = (t_longword)dst;
	srcp = (t_longword)src;
	while (dstp % 8)
	{
		if ((*(t_byte *)dstp = *(t_byte *)srcp) == 0)
			return (dst);
		dstp += 1;
		srcp += 1;
	}
	if (srcp % 8 == 0)
		strcpy_same_alignement(dstp, srcp);
	else
		strcpy_not_same_alignement(dstp, srcp, srcp % 8);
	return (dst);
}
