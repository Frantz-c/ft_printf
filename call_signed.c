/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   call_signed.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 11:58:11 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 16:21:50 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		call_llong(void (*call)(), t_opt *o, va_list ap)
{
	return ((int (*)(long long, t_opt*))call)(va_arg(ap, long long), o);
}

int		call_long(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(long long, t_opt*))call)(va_arg(ap, long), o));
}

int		call_int(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(long long, t_opt*))call)(va_arg(ap, int), o));
}

int		call_short(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(long long, t_opt *o))call)((short)va_arg(ap, int), o));
}

int		call_char(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(long long, t_opt *o))call)((char)va_arg(ap, int), o));
}
