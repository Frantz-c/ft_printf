/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   call.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 12:07:29 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 10:33:42 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CALL_H
# define CALL_H

int		call_uintmax_t(void (*call)(), t_opt *o, va_list ap);
int		call_size_t(void (*call)(), t_opt *o, va_list ap);
int		call_ulong(void (*call)(), t_opt *o, va_list ap);
int		call_ullong(void (*call)(), t_opt *o, va_list ap);
int		call_uint(void (*call)(), t_opt *o, va_list ap);
int		call_ushort(void (*call)(), t_opt *o, va_list ap);
int		call_uchar(void (*call)(), t_opt *o, va_list ap);
int		call_ptr(void (*call)(), t_opt *o, va_list ap);
int		call_llong(void (*call)(), t_opt *o, va_list ap);
int		call_ssize_t(void (*call)(), t_opt *o, va_list ap);
int		call_intmax_t(void (*call)(), t_opt *o, va_list ap);
int		call_float(void (*call)(), t_opt *o, va_list ap);
int		call_double(void (*call)(), t_opt *o, va_list ap);
int		call_long(void (*call)(), t_opt *o, va_list ap);
int		call_ldouble(void (*call)(), t_opt *o, va_list ap);
int		call_int(void (*call)(), t_opt *o, va_list ap);
int		call_short(void (*call)(), t_opt *o, va_list ap);
int		call_char(void (*call)(), t_opt *o, va_list ap);

int		call_wchar_t_fl(void (*call)(), t_opt *o, va_list ap);
int		call_ulong_fl(void (*call)(), t_opt *o, va_list ap);
int		call_ullong_fl(void (*call)(), t_opt *o, va_list ap);
int		call_uint_fl(void (*call)(), t_opt *o, va_list ap);
int		call_ushort_fl(void (*call)(), t_opt *o, va_list ap);
int		call_uchar_fl(void (*call)(), t_opt *o, va_list ap);
int		call_llong_fl(void (*call)(), t_opt *o, va_list ap);
int		call_long_fl(void (*call)(), t_opt *o, va_list ap);
int		call_int_fl(void (*call)(), t_opt *o, va_list ap);
int		call_short_fl(void (*call)(), t_opt *o, va_list ap);
int		call_char_fl(void (*call)(), t_opt *o, va_list ap);

#endif
