/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 09:48:49 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 11:26:04 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "functions/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <stdio.h>
# include <string.h>
# include <_types/_intmax_t.h>
# include <_types/_uintmax_t.h>

# define L_LMAJ		0x1
# define L_L		0x2
# define L_LL		0x3
# define L_H		0x4
# define L_HH		0x5
# define L_Z		0x6
# define L_J		0x7
# define L_MAX		L_J

# define PLUS		0x1
# define MINUS		0x2
# define SPACE		0x4
# define ZERO		0x8
# define SHARP		0x10

# define LENGTH_NOT_EXPECTED	0x1U
# define VLEN_FLOAT_EXPECTED	0x2U
# define IS_UNSIGNED_FUNCTION	0x8U

# define CHARMAX	0x7fU
# define SHORTMAX	0x7fffU
# define INTMAX		0x7fffffffU
# define LONGMAX	0x7fffffffffffffffUL

# define FT_INF64_P	0x7ff0000000000000UL
# define FT_INF64_N	0xfff0000000000000UL

struct	s_opt
{
	int		flag;
	int		width;
	int		precision;
	int		length;
	int		curlen;
};

struct	s_ydata
{
	void			*next;
	void			*ptr;
	const char		*s;
	const char		*start;
	int				u;
	int				offset;
	int				n_elem;
};

typedef struct s_opt	t_opt;
typedef struct s_ydata	t_ydata;

typedef void	(*t_voidf)();
typedef void	(*t_vf)();
typedef int		(*t_call)(void (*)(), t_opt *, va_list);
typedef int		(*t_yspe)(void*, t_opt*, const char **);

int		ft_printf(const char *fmt, ...);
int		print_conv(const t_byte **string, t_opt *o, va_list ap);

void	get_sign(t_opt *o, int neg, char *sign);
int		print_number_with_options(char *n, t_opt *o, int neg);
int		print_string_with_options(const char *s, t_opt *o, int len);
int		unicode_to_utf8(wchar_t c, char *utf8);
int		call_convertion_function(const t_byte **s, t_opt *o, va_list ap);

int		cmaj_spe(wchar_t c, t_opt *o);
int		smaj_spe(const wchar_t *s, t_opt *o);
int		zmaj_spe(char **t, t_opt *o);
int		ymaj_spe(void *t, t_opt *o);
int		wmaj_spe(void *ptr, t_opt *o, const char **fmt);
int		c_spe(int c, t_opt *o);
int		n_spe(void *n, t_opt *o);
int		x_spe(t_ullong n, t_opt *o);
int		p_spe(t_ullong n, t_opt *o);
int		xmaj_spe(t_ullong n, t_opt *o);
int		s_spe(const char *s, t_opt *o);
int		u_spe(t_ullong n, t_opt *o);
int		di_spe(long long n, t_opt *o);
int		b_spe(t_ullong n, t_opt *o);
int		v_spe(double n, t_opt *o);
int		lv_spe(long double n, t_opt *o);
int		o_spe(t_ullong n, t_opt *o);
int		w_spe(void *ptr, t_opt *o, const char **fmt);
int		y_spe(void *t, t_opt *o);
int		f_spe(double n, t_opt *o);
int		lf_spe(long double n, t_opt *o);

#endif
