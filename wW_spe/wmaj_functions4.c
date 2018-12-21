/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wmaj_functions4.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 17:50:48 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 19:50:59 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../functions/libft.h"
#include "wmaj_specifier.h"

extern int			is_recognized_type(const char *fmt)
{
	int					i;

	if (*fmt == 'u')
		fmt += (!ft_strncmp(fmt + 1, "nsigned ", 8)) ? 9 : 1;
	i = 0;
	while (i < TYPECOUNT)
	{
		if (!ft_strncmp(fmt, g_wtype[i], g_wlen[i]))
			return (1);
		i++;
	}
	if (!ft_strncmp(fmt, "next", 4))
	{
		if (fmt[4] != ',' && fmt[4] != ';')
			return (0);
		return (1);
	}
	else if (!ft_strncmp(fmt, "pad", 3))
		return (1);
	return (0);
}

extern void			add_include(t_inc **includes, char *path, char *path2)
{
	t_inc	*new;
	t_inc	*tmp;
	char	*tmps;

	if (!path)
		tmps = path2;
	else
		tmps = path;
	if (is_duplicate(*includes, tmps))
	{
		free(tmps);
		return ;
	}
	new = malloc(sizeof(t_inc));
	new->next = NULL;
	new->s = tmps;
	if (!*includes)
	{
		*includes = new;
		return ;
	}
	tmp = *includes;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

extern int			no_remaind_typedef(t_tlist *types)
{
	while (types)
	{
		if (!types->real_t)
			return (0);
		types = types->next;
	}
	return (1);
}

extern int			unused_typedef(t_tlist *types)
{
	while (types)
	{
		if (!types->used)
			return (0);
		types = types->next;
	}
	return (1);
}
