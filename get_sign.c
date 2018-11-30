/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_sign.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 14:00:23 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 11:16:54 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

extern void		get_sign(t_opt *o, int neg, char *sign)
{
	sign[1] = '\0';
	if (!neg)
	{
		if (o->flag & PLUS)
			*sign = '+';
		else if (o->flag & SPACE)
			*sign = ' ';
		else
			*sign = '\0';
		return ;
	}
	if (neg > '0')
	{
		*sign = '0';
		sign[1] = neg;
	}
	else if (neg == 1)
		*sign = '-';
	else
		*sign = neg;
}
