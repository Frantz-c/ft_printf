/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   is_nan.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 20:05:09 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 11:51:59 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ulong128.h"
#include "ft_printf.h"

/*
**	long double NAN & INF
*/

extern int		is_inf_or_nan_ld(int sign, t_ulong n, char *buf)
{
	if (n == 0x8000000000000000UL)
	{
		ft_strcpy(buf, "inf");
		return (3 + (sign != 0));
	}
	ft_strcpy(buf, "nan");
	return (3);
}

extern inline int	is_inf_or_nan2(t_ulong128 *n, int sign, char *buf)
{
	if ((n->hi & 0x7fffUL) == 0x0000000000007fffUL)
		return (is_inf_or_nan_ld(sign, n->lo, buf));
	return (0);
}

/*
**	double NAN & INF
*/

extern int			is_inf_or_nan_d(t_ulong n, char *buf)
{
	if ((n ^ 0x8000000000000000UL) == FT_INF64_P)
	{
		ft_strcpy(buf, "inf");
		return (3 + ((n & 0x8000000000000000UL) != 0));
	}
	ft_strcpy(buf, "nan");
	return (3);
}
