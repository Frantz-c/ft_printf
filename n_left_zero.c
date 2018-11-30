/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   n_left_zero.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 22:09:14 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/23 22:11:20 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int			get_left_zero_count2(t_ulong decimal)
{
	if (decimal > 999999UL)
		return (12);
	if (decimal > 99999UL)
		return (13);
	if (decimal > 9999UL)
		return (14);
	if (decimal > 999UL)
		return (15);
	if (decimal > 99UL)
		return (16);
	if (decimal > 9UL)
		return (17);
	return (18);
}

extern inline int	get_left_zero_count(t_ulong decimal)
{
	if (decimal > 999999999999999999UL)
		return (0);
	if (decimal > 99999999999999999UL)
		return (1);
	if (decimal > 9999999999999999UL)
		return (2);
	if (decimal > 999999999999999UL)
		return (3);
	if (decimal > 99999999999999UL)
		return (4);
	if (decimal > 9999999999999UL)
		return (5);
	if (decimal > 999999999999UL)
		return (6);
	if (decimal > 99999999999UL)
		return (7);
	if (decimal > 9999999999UL)
		return (8);
	if (decimal > 999999999UL)
		return (9);
	if (decimal > 99999999UL)
		return (10);
	if (decimal > 9999999UL)
		return (11);
	return (get_left_zero_count2(decimal));
}
