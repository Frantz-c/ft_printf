/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wmaj_functions3.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 17:42:55 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 11:00:21 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../functions/libft.h"
#include "wmaj_specifier.h"

static inline void	search_include(char *p, t_inc **inc)
{
	char	*tmp;
	char	*path;

	if (*p == '#')
	{
		if (!ft_strncmp(++p, "include ", 8) || !ft_strncmp(++p, "include ", 8))
		{
			if (p[8] == '"' && (tmp = ft_strchr(p + 9, '"')))
			{
				path = ft_strndup(p + 9, tmp - (p + 9));
				add_include(inc, NULL, path);
			}
			else if (p[8] == '<' && (tmp = ft_strchr(p + 9, '>')))
			{
				path = ft_strndup(p + 9, tmp - (p + 9));
				add_include(inc, strjoin_path("/usr/include", path), NULL);
				free(path);
			}
		}
	}
}

static inline int	search_typedef(char *p, t_tlist *types)
{
	char	*tmp;
	char	*tmp2;

	if (!ft_strncmp(p, "typedef ", 8))
		while (types)
		{
			tmp = p + 7;
			while ((tmp = ft_strstr(tmp + 1, types->unknown)))
			{
				if (tmp[-1] == ' ' && tmp[ft_strlen(types->unknown)] == ';')
				{
					tmp2 = ft_strndup(p + 8, (tmp - 1) - (p + 8));
					if (is_recognized_type(tmp2))
					{
						types->real_t = tmp2;
						return (1);
					}
					else
						free(tmp2);
				}
			}
			types = types->next;
		}
	return (0);
}

static inline void	search_typedef_in_files(t_inc *inc, t_tlist *types,
													int fd, char *buf)
{
	char	*p;
	t_inc	*file;

	file = inc;
	while (file)
	{
		if ((fd = open(file->s, O_RDONLY)) > 0)
		{
			buf = NULL;
			while (get_next_line(fd, &buf) == 1)
			{
				p = trim_space_comment(buf);
				if (search_typedef(p, types) && no_remaind_typedef(types))
				{
					free(buf);
					return ;
				}
				search_include(p, &inc);
			}
			get_next_line(fd, NULL);
			close(fd);
		}
		file = file->next;
	}
	free(buf);
}

extern inline void	search_typedef_and_includes(t_inc **inc,
												t_tlist *types, int fd)
{
	char	*buf;
	char	*p;

	buf = NULL;
	while (get_next_line(fd, &buf) == 1)
	{
		p = trim_space_comment(buf);
		if (search_typedef(p, types) && no_remaind_typedef(types))
		{
			free(buf);
			get_next_line(fd, NULL);
			return ;
		}
		search_include(p, inc);
	}
	get_next_line(fd, NULL);
	close(fd);
	if (*inc)
		search_typedef_in_files(*inc, types, fd, buf);
}

extern int			print_no_recognized_types_list(t_tlist *types)
{
	int		count;

	count = 0;
	while (types)
	{
		if (types->real_t == NULL)
			count += ft_printf("[ERROR: unknown type \"%s\"]",
					types->unknown);
		types = types->next;
	}
	if (count)
		free_types(types);
	return (count);
}
