/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   call_unsigned2.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 16:12:38 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 20:00:40 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		call_size_t(void (*call)(), t_opt *o, va_list ap)
{
	return ((int (*)(t_ullong, t_opt*))call)(va_arg(ap, size_t), o);
}

int		call_ptr(void (*call)(), t_opt *o, va_list ap)
{
	return ((int (*)(void*, t_opt*))call)(va_arg(ap, void*), o);
}

int		call_uintmax_t(void (*call)(), t_opt *o, va_list ap)
{
	return (((int (*)(t_ullong, t_opt*))call)(va_arg(ap, uintmax_t), o));
}
