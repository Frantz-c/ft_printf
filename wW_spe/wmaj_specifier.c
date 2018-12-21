/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wmaj_specifier.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 00:45:57 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 18:53:07 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "wmaj_specifier.h"
#include "../functions/libft.h"

/*
**	"%Wnom,file;"
**	exemple -> "%Ws_struct,file;"
**
**	w_fmt = "int=inode,uint=mode,next;"
*/

static inline char	*format_struct(t_l *l, const char *sname, int fd, int *err)
{
	char		*wfmt;
	t_tlist		*types;

	(void)sname;
	types = NULL;
	if (contain_unknown_typedef(l, &types))
	{
		if ((*err = get_real_types(l, fd, types, err) != 0))
		{
			free_l(l);
			return (NULL);
		}
	}
	get_next_line(fd, NULL);
	wfmt = malloc_wfmt(l);
	set_wfmt(wfmt, l);
	free_l(l);
	return (wfmt);
}

static char			*get_typedef_definition(char *p, const char *name, int len)
{
	if (!ft_strncmp(p, name, len) && p[len] == ' ')
		return (ft_strndup(p + len + 1, ft_strlen(p + len + 2)));
	return (NULL);
}

static char			*get_struct_definition(const char *name, int len,
		int fd, int *error)
{
	char	*buf;
	char	*p;
	char	*wfmt;
	t_l		*list;
	char	*tpf;

	assign_null_2a((void*)&buf, (void*)&tpf);
	while (get_next_line(fd, &buf) == 1)
	{
		p = trim_space_comment(buf);
		if (!tpf && !ft_strncmp(p, "typedef struct ", 15)
				&& ft_strchr(p + 15, ';'))
			tpf = get_typedef_definition(p + 15, name, len);
		else if ((p = ft_strstr(p, "struct ")))
		{
			if (!ft_strncmp(p + 7, name, len) && !p[len + 7])
			{
				list = (get_struct(fd, ft_strchr(p + 7 + len, '{'), name, tpf));
				wfmt = format_struct(list, name, fd, error);
				return (free_arg1_arg2_and_return_arg3(buf, tpf, wfmt));
			}
		}
	}
	*error = ft_printf("[ERROR: struct '%s' not found]", name);
	return (free_arg1_arg2_and_return_arg3(tpf, buf, NULL));
}

extern inline char	*get_infos(const char **fmt, char **sn,
		char **fn, int *error)
{
	const char	*p = *fmt;
	int			sn_length;
	int			fn_length;
	char		*w_fmt;
	int			fd;

	while (*p && *p != ',')
		p++;
	sn_length = p - *fmt;
	p++;
	while (*p && *p != ';')
		p++;
	fn_length = p - (*fmt + sn_length + 1);
	*sn = ft_strndup(*fmt, sn_length);
	*fn = ft_strndup(*fmt + sn_length + 1, fn_length);
	*fmt += sn_length + 1 + fn_length;
	if ((fd = open(*fn, O_RDONLY)) == -1)
	{
		*error = (ft_printf("[ERROR: '%s' file does not exists", *fn));
		return (NULL);
	}
	w_fmt = get_struct_definition(*sn, sn_length, fd, error);
	get_next_line(fd, NULL);
	close(fd);
	return (w_fmt);
}

extern int			wmaj_spe(void *ptr, t_opt *o, const char **fmt)
{
	char	*struct_name;
	char	*file_name;
	char	*w_fmt;
	int		count;

	(*fmt)++;
	if ((w_fmt = get_infos(fmt, &struct_name, &file_name, &count)) != NULL)
	{
		count = ft_printf("STRUCT %s:", struct_name);
		if (o->width == -1)
		{
			w_fmt[1] = 'z';
			count += ft_printf(w_fmt, ptr);
		}
		else
			count += ft_printf(w_fmt, o->width, ptr);
		free(w_fmt);
	}
	free(struct_name);
	free(file_name);
	return (count);
}
