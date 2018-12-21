/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ulong128_assign.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 18:39:56 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 18:42:34 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ulong128.h"
#include "numeric_str_op.h"
#include "../ft_printf.h"

static void			ulong128_assign_set_var(t_ulong128 *n, t_ulong *curs,
										int *i, t_ulong **curn)
{
	n->hi = 0;
	n->lo = 0;
	*curs = 0x8000000000000000UL;
	*i = 127;
	*curn = &n->hi;
}

extern inline void	ulong128_assign(t_ulong128 *n, char *strn)
{
	char	s[50];
	char	*start;
	int		i;
	t_ulong	curs;
	t_ulong *curn;

	ulong128_assign_set_var(n, &curs, &i, &curn);
	start = ft_strcpy(s, strn);
	while (*start != '0')
	{
		if (numeric_str_cmp(start, g_bitvalue[i]) > -1)
		{
			start += numeric_str_sub(start, g_bitvalue[i]);
			*curn |= curs;
		}
		curs >>= 1;
		i--;
		if (!curs)
		{
			if (curn == &n->lo)
				break ;
			curn = &n->lo;
			curs = 0x8000000000000000UL;
		}
	}
}
