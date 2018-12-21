/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wmaj_functions.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 17:17:46 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 10:55:35 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../functions/libft.h"
#include "wmaj_specifier.h"

extern char			*malloc_wfmt(t_l *l)
{
	char	*wfmt;
	int		len;

	len = 1;
	while (l)
	{
		len += l->ss_len + 2;
		l = l->next;
	}
	wfmt = malloc(len + 4);
	*wfmt = '%';
	wfmt[1] = '*';
	wfmt[2] = 'w';
	wfmt[3] = '\0';
	return (wfmt);
}

extern void			set_wfmt(char *wfmt, t_l *l)
{
	const t_l	*start = l;

	while (l)
	{
		if (l != start)
			ft_strcat(wfmt, ",");
		if (*l->name == '0')
			ft_strcat(wfmt, l->type);
		else
		{
			ft_strcat(wfmt, l->type);
			ft_strcat(wfmt, "=");
			ft_strcat(wfmt, l->name);
		}
		l = l->next;
	}
	ft_strcat(wfmt, ";");
}

static inline void	add_info_struct(t_l **l, char *info)
{
	t_l		*new;
	t_l		*tmp;
	char	*p;

	delete_space_before_star(info);
	new = malloc(sizeof(t_l));
	p = ft_strchr(info, ' ');
	new->type = ft_strndup(info, p - info);
	new->ss_len = ft_strlen(p + 1) - 1;
	new->name = ft_strndup(p + 1, new->ss_len);
	if (new->name[new->ss_len - 1] == ' ')
		new->name[new->ss_len - 1] = '\0';
	new->ss_len += (p - info);
	new->next = NULL;
	if (!*l)
	{
		*l = new;
		return ;
	}
	tmp = *l;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

static inline int	set_struct(char *p, const char *sname,
									t_l **list, char *tpdf)
{
	if (*p == '}')
		return (1);
	if ((ft_strstr(p, sname) || (tpdf && ft_strstr(p, tpdf)))
		&& ft_strstr(p + 1, "next"))
		add_info_struct(list, "next 0x");
	else
		add_info_struct(list, p);
	if (ft_strchr(p + 1, '}'))
		return (1);
	return (0);
}

extern inline t_l	*get_struct(int fd, char *open,
									const char *name, char *tpdf)
{
	char	*buf;
	char	*p;
	t_l		*list;

	assign_null_2a((void*)&list, (void*)&buf);
	while (get_next_line(fd, &buf) == 1)
	{
		if (*(p = trim_space_comment(buf)) == '{' || open)
		{
			if (p[1])
			{
				if ((ft_strstr(p + 1, name) || ft_strstr(p + 1, tpdf))
						&& ft_strstr(p + 2, "next"))
					add_info_struct(&list, "next 0x");
				else
					add_info_struct(&list, p + 1);
			}
			while (get_next_line(fd, &buf) == 1 &&
					!(set_struct(trim_space_comment(buf), name, &list, tpdf)))
				;
			break ;
		}
	}
	get_next_line(fd, NULL);
	return (free_arg1_arg2_and_return_arg3(buf, NULL, list));
}
