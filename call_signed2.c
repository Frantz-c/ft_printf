/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   call_signed2.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 11:59:58 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 11:33:15 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		call_ssize_t(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(long long, t_opt*))call)(va_arg(ap, ssize_t), o));
}

int		call_float(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(double, t_opt*))call)((float)va_arg(ap, double), o));
}

int		call_double(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(double, t_opt*))call)(va_arg(ap, double), o));
}

int		call_ldouble(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(long double, t_opt*))call)(va_arg(ap, long double), o));
}

int		call_intmax_t(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(long long, t_opt*))call)(va_arg(ap, intmax_t), o));
}
