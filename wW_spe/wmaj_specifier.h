/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wmaj_specifier.h                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 17:16:05 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 10:59:25 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WMAJ_SPECIFIER_H
# define WMAJ_SPECIFIER_H

# define DEBUG_LIST		"%wnext,char*=name,char*=type,int=ss_len;"
# define DEBUG_TLIST	"%wchar*=unknown,char*=real_t,int=used,next;"

# include "w_global.h"
# include "../ft_printf.h"
# include <dirent.h>
# include <fcntl.h>

/*
**	contient tous les types et les noms des membres
**	de la structure a afficher.
**	ss_len = strlen(name) + strlen(type);
*/

struct		s_l
{
	struct s_l		*next;
	char			*name;
	char			*type;
	int				ss_len;
};

/*
**	contient tous les types inconnus, et leur traduction si trouvee.
*/

struct		s_tlist
{
	char			*unknown;
	char			*real_t;
	int				used;
	struct s_tlist	*next;
};

/*
**	contient la liste des .h dans lesquels chercher les typedef inconnus
*/

struct		s_inc
{
	char			*s;
	struct s_inc	*next;
};

typedef struct s_l		t_l;
typedef struct s_tlist	t_tlist;
typedef struct s_inc	t_inc;

extern char	*malloc_wfmt(t_l *l);
extern void	set_wfmt(char *wfmt, t_l *l);
extern t_l	*get_struct(int fd, char *open, const char *name, char *tpdf);
extern int	get_real_types(t_l *l, int fd, t_tlist *types, int *error);
extern int	contain_unknown_typedef(t_l *l, t_tlist **types);
extern void	delete_space_before_star(char *info);
extern void	search_typedef_and_includes(t_inc **inc, t_tlist *types, int fd);
extern int	print_no_recognized_types_list(t_tlist *types);
extern int	is_recognized_type(const char *fmt);
extern void	add_include(t_inc **includes, char *path, char *path2);
extern int	no_remaind_typedef(t_tlist *types);
extern int	unused_typedef(t_tlist *types);
extern int	is_duplicate(t_inc *includes, char *tmps);
extern int	replace_types(t_l *l, t_tlist *types, int *error);
extern char	*trim_space_comment(char *s);
extern void	free_types(t_tlist *types);
extern void	free_includes_list(t_inc *inc);
extern void	free_l(t_l *l);

#endif
