/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   call_unsigned3.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 12:18:18 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 12:19:30 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		call_ulong_fl(void (*call)(), t_opt *o, va_list ap)
{
	return ((int (*)(t_ulong, t_opt*))call)(va_arg(ap, t_ulong), o);
}

int		call_ullong_fl(void (*call)(), t_opt *o, va_list ap)
{
	return ((int (*)(t_ullong, t_opt*))call)(va_arg(ap, t_ullong), o);
}

int		call_uint_fl(void (*call)(), t_opt *o, va_list ap)
{
	return ((int (*)(t_uint, t_opt*))call)(va_arg(ap, t_uint), o);
}

int		call_ushort_fl(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(t_ush, t_opt *o))call)((t_ush)va_arg(ap, t_uint), o));
}

int		call_uchar_fl(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(t_byte, t_opt *o))call)((t_byte)va_arg(ap, int), o));
}
