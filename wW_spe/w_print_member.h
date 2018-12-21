/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   w_print_member.h                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 10:55:59 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 10:46:03 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef W_PRINT_MEMBER_H
# define W_PRINT_MEMBER_H

# include "../ft_printf.h"

typedef int	(*t_print)(int*, const char**, void*, int);

int			print_str(int *offset, const char **s, void *ptr, int u);
int			print_char(int *offset, const char **s, void *ptr, int u);
int			print_double(int *offset, const char **s, void *ptr, int u);
int			print_float(int *offset, const char **s, void *ptr, int u);
int			print_ldouble(int *offset, const char **s, void *ptr, int u);
int			print_ptr(int *offset, const char **s, void *ptr, int u);
int			print_long(int *off, const char **s, void *ptr, int u);
int			print_llong(int *off, const char **s, void *ptr, int u);
int			print_int(int *offset, const char **s, void *ptr, int u);
int			print_short(int *offset, const char **s, void *ptr, int u);
int			print_direct_str(int *offset, const char **s, void *ptr, int u);
int			print_intmax_t(int *offset, const char **s, void *ptr, int u);
int			print_ssize_t(int *offset, const char **s, void *ptr, int u);
int			print_size_t(int *offset, const char **s, void *ptr, int u);
int			padding(const char *s, int *offset);
void		call_recursive(t_ydata *d, int *count);
int			get_padding(int addr, size_t size);
const char	*print_data(t_ydata d, int *count);

#endif
