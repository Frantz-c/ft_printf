/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putc.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 16:44:58 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:36:13 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

int		c_spe(int c, t_opt *o)
{
	int	ret;

	c = (t_byte)c;
	if (o->width > 1)
	{
		o->width -= 1;
		if (o->flag & MINUS)
		{
			ret = write(1, &c, 1) + o->width;
			while (o->width--)
				write(1, " ", 1);
			return (ret);
		}
		o->length = (o->flag & ZERO) ? '0' : ' ';
		ret = o->width;
		while (o->width--)
			write(1, &o->length, 1);
		return (ret + write(1, &c, 1));
	}
	return (write(1, &c, 1));
}
