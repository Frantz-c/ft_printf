/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 11:04:16 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 10:39:03 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static inline int	memcmp_no_alignement(t_byte *p1, t_byte *p2, size_t n)
{
	long int		result;
	t_longword		a;
	t_longword		b;

	while (n)
	{
		a = *p1;
		b = *p2;
		result = a - b;
		if (result || !a)
			return (result);
		p1 += 1;
		p2 += 1;
		n -= 1;
	}
	return (0);
}

static inline int	memcmp_same_alignement(const t_longword *s1,
						const t_longword *s2, size_t n, size_t n_word)
{
	t_longword			word;

	while (n_word)
	{
		word = *s1;
		if (*s1 != *s2
			|| ((word - 0x0101010101010101UL) & ~word & 0x8080808080808080UL))
		{
			n += 8;
			return (memcmp_no_alignement((t_byte *)s1, (t_byte *)s2, n));
		}
		s1++;
		s2++;
		n_word--;
	}
	return (0);
}

static inline int	memcmp_not_same_alignement(const t_longword *s1,
						const t_longword *s2, size_t n, size_t shift)
{
	t_longword			merge;
	const size_t		shr = shift * 8;
	const size_t		shl = (8 - shift) * 8;

	s2 = (t_longword *)((t_longword)s2 - shift);
	while (n > 7)
	{
		merge = *s2 >> shr | *(s2 + 1) << shl;
		if (*s1 != merge || ((merge - 0x0101010101010101UL)
							& ~merge & 0x8080808080808080UL))
			break ;
		s1++;
		s2++;
		n -= 8;
	}
	if (n == 0)
		return (0);
	return (memcmp_no_alignement((t_byte *)s1, (t_byte *)s2 + shift, n));
}

extern inline int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	long int a;
	long int b;
	long int result;

	if (n > 16)
	{
		while ((t_longword)s1 % 8)
		{
			a = *((t_byte *)s1);
			b = *((t_byte *)s2);
			result = a - b;
			if (result || !a)
				return (result);
			s1 += 1;
			s2 += 1;
			n -= 1;
		}
		if ((t_longword)s2 % 8 == 0)
			return (memcmp_same_alignement((t_longword *)s1,
									(t_longword *)s2, n % 8, n / 8));
		else
			return (memcmp_not_same_alignement((t_longword *)s1,
								(t_longword *)s2, n, (t_longword)s2 % 8));
	}
	return (memcmp_no_alignement((t_byte *)s1, (t_byte *)s2, n));
}
