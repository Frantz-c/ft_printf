/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wmaj_free.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 17:22:30 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:48:09 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "wmaj_specifier.h"

extern void				free_l(t_l *l)
{
	t_l		*tofree;

	while (l)
	{
		tofree = l;
		l = l->next;
		free(tofree->type);
		free(tofree->name);
		free(tofree);
	}
}

extern void				free_includes_list(t_inc *inc)
{
	t_inc	*tofree;

	while (inc)
	{
		if (inc->s)
			free(inc->s);
		tofree = inc;
		inc = inc->next;
		free(tofree);
	}
}

extern void				free_types(t_tlist *types)
{
	t_tlist		*tofree;

	while (types)
	{
		if (types->real_t)
			free(types->real_t);
		if (types->unknown)
			free(types->unknown);
		tofree = types;
		types = types->next;
		free(tofree);
	}
}
