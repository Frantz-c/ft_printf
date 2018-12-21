/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   call_unsigned.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 12:04:22 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 09:42:06 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		call_ulong(void (*call)(), t_opt *o, va_list ap)
{
	return ((int (*)(t_ullong, t_opt*))call)(va_arg(ap, t_ulong), o);
}

int		call_ullong(void (*call)(), t_opt *o, va_list ap)
{
	return ((int (*)(t_ullong, t_opt*))call)(va_arg(ap, t_ullong), o);
}

int		call_uint(void (*call)(), t_opt *o, va_list ap)
{
	return ((int (*)(t_ullong, t_opt*))call)(va_arg(ap, t_uint), o);
}

int		call_ushort(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(t_ullong, t_opt *o))call)((t_ush)va_arg(ap, t_uint), o));
}

int		call_uchar(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(t_ullong, t_opt *o))call)((t_byte)va_arg(ap, int), o));
}
