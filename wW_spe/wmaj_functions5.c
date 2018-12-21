/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wmaj_functions5.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 17:53:52 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 19:51:10 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../functions/libft.h"
#include "wmaj_specifier.h"

extern int		is_duplicate(t_inc *includes, char *tmps)
{
	while (includes)
	{
		if (ft_strcmp(includes->s, tmps) == 0)
			return (1);
		includes = includes->next;
	}
	return (0);
}

extern int		replace_types(t_l *l, t_tlist *types, int *error)
{
	t_l *tmp;

	while (types)
	{
		tmp = l;
		while (tmp)
		{
			if (types->real_t == NULL)
			{
				*error = ft_printf("[ERROR: type \"%s\" not found]",
						types->unknown);
				return (-1);
			}
			if ((types->unknown && ft_strcmp(types->unknown, tmp->type) == 0))
			{
				free(tmp->type);
				tmp->type = ft_strdup(types->real_t);
				tmp->ss_len = ft_strlen(tmp->type) + ft_strlen(tmp->name);
				types->used = 1;
			}
			tmp = tmp->next;
		}
		types = types->next;
	}
	return (0);
}
