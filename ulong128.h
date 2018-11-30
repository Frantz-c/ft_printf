/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   long128.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/28 11:56:52 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 18:55:59 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ULONG128_H
# define ULONG128_H

# include "ft_printf.h"

typedef struct	s_ulong128
{
	t_ulong	lo;
	t_ulong	hi;
}				t_ulong128;

extern void		ulong128_shr(t_ulong128 *n);
extern void		ulong128_shl(t_ulong128 *n);
extern void		ulong128_add(t_ulong128 *a, t_ulong128 *b);
extern char		*ulong128_to_ascii(char *str, t_ulong128 *n, int bufsiz);
extern void		ulong128_assign(t_ulong128 *n, char *strn);

#endif
