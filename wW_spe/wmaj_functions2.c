/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wmaj_functions2.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 17:39:49 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 10:49:32 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../functions/libft.h"
#include "wmaj_specifier.h"

extern int			get_real_types(t_l *l, int fd,
							t_tlist *types, int *error)
{
	t_inc	*inc;

	inc = NULL;
	lseek(fd, 0, SEEK_SET);
	search_typedef_and_includes(&inc, types, fd);
	free_includes_list(inc);
	if (unused_typedef(types))
		return (print_no_recognized_types_list(types));
	if (replace_types(l, types, error) == -1)
	{
		free_types(types);
		return (*error);
	}
	free_types(types);
	return (0);
}

static void			add_type_to_tlist(t_tlist **types, char *type)
{
	t_tlist		*new;
	t_tlist		*tmp;

	new = malloc(sizeof(t_tlist));
	new->unknown = ft_strdup(type);
	new->real_t = NULL;
	new->next = NULL;
	new->used = 0;
	if (*types == NULL)
	{
		*types = new;
		return ;
	}
	tmp = *types;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

static int			not_in_list(const char *type, t_tlist *types)
{
	while (types)
	{
		if (!ft_strcmp(types->unknown, type))
			return (0);
		types = types->next;
	}
	return (1);
}

extern inline int	contain_unknown_typedef(t_l *l, t_tlist **types)
{
	int			unknown;

	unknown = 0;
	while (l)
	{
		if (ft_strcmp(l->type, "next") && !is_recognized_type(l->type)
				&& not_in_list(l->type, *types))
		{
			add_type_to_tlist(types, l->type);
			unknown = 1;
		}
		l = l->next;
	}
	return (unknown);
}

extern void			delete_space_before_star(char *info)
{
	if ((info = ft_strchr(info, '*')))
	{
		if (info[-1] == ' ')
		{
			info[-1] = '*';
			info[0] = ' ';
		}
	}
}
