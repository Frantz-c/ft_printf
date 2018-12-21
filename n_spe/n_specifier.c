/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   n_specifier.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 14:57:49 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 12:25:19 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

int		n_spe(void *n, t_opt *o)
{
	if (o->length == L_LL)
		*(long long*)n = o->curlen;
	else if (o->length == L_L)
		*(long*)n = o->curlen;
	else if (o->length == L_H)
		*(short*)n = o->curlen;
	else if (o->length == L_HH)
		*(char*)n = o->curlen;
	else if (o->length == L_Z)
		*(ssize_t*)n = o->curlen;
	else if (o->length == L_J)
		*(intmax_t*)n = o->curlen;
	else
		*(int*)n = o->curlen;
	return (0);
}
