/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wmaj_format_string.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 17:26:00 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 10:48:46 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../functions/libft.h"
#include "wmaj_specifier.h"

static void				delete_comment_iscom(char *s)
{
	char	*p;

	if ((p = ft_strstr(s, "*/")) == NULL)
		return ;
	while (*p)
	{
		*p = ' ';
		p[1] = ' ';
		p += 2;
		while (*p && (*p != '*' || p[1] != '/'))
			*(p++) = ' ';
		if (!*p)
			return ;
		*p = ' ';
		p[1] = ' ';
	}
	return ;
}

static int				delete_comment_notcom(char **p, char **p2, int *iscom)
{
	if (*p && ((!*p2) || (*p < *p2)))
	{
		**p = ' ';
		(*p)[1] = ' ';
		*p += 2;
		while (**p && (**p != '*' || (*p)[1] != '/'))
			*((*p)++) = ' ';
		if (!**p)
		{
			*iscom = 1;
			return (1);
		}
		**p = ' ';
		(*p)[1] = ' ';
	}
	else if (*p2)
	{
		ft_memset(*p2, '\0', ft_strlen(*p2));
		return (1);
	}
	else
		return (1);
	return (0);
}

static inline void		replace_comment_line(char *s)
{
	static int	iscom = 0;
	char		*p;
	char		*p2;

	p2 = NULL;
	if (iscom)
	{
		delete_comment_iscom(s);
		iscom = 0;
		return ;
	}
	p = s;
	while (1)
	{
		if (!p)
			return ;
		p2 = ft_strstr(p, "//");
		p = ft_strstr(p, "/*");
		if (delete_comment_notcom(&p, &p2, &iscom) == 1)
			return ;
	}
}

static inline char		*trim(char *s)
{
	const char	*org = s;
	char		*start;
	char		*space_start;
	char		*new;

	start = s;
	new = s;
	space_start = s;
	while (*s)
	{
		while (*s && !is_space(*s))
			s++;
		if (is_space(*s))
			*(s++) = ' ';
		space_start = s;
		while (is_space(*s))
			s++;
		ft_memmove(new, start, space_start - start);
		new += space_start - start;
		start = s;
	}
	if (*new && new != org)
		*new = '\0';
	return (skip_spaces(org));
}

extern inline char		*trim_space_comment(char *s)
{
	replace_comment_line(s);
	return (trim(s));
}
