/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putc.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 16:44:58 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 14:21:31 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		c_specifier(int c, t_opt *o)
{
	(void)o;
	return (write(1, &c, 1));
}