/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ltoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 12:06:57 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/23 21:37:20 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

extern int		ultoa_buf(t_ulong n, char *buf)
{
	char tmp[21];
	char *p;

	p = tmp + 20;
	*tmp = '\0';
	while (1)
	{
		*(--p) = (n % 10) + 48;
		n /= 10;
		if (!n)
			break ;
	}
	ft_strcpy(buf, p);
	return ((tmp + 20) - p);
}
