/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   call_signed3.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 12:16:14 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 12:18:03 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		call_llong_fl(void (*call)(), t_opt *o, va_list ap)
{
	return ((int (*)(long long, t_opt*))call)(va_arg(ap, long long), o);
}

int		call_long_fl(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(long, t_opt*))call)(va_arg(ap, long), o));
}

int		call_int_fl(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(int, t_opt*))call)(va_arg(ap, int), o));
}

int		call_short_fl(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(short, t_opt *o))call)((short)va_arg(ap, int), o));
}

int		call_char_fl(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(char, t_opt *o))call)((char)va_arg(ap, int), o));
}
