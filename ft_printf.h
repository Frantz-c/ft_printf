/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 09:48:49 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 21:16:17 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

# define LEN_LF		0x1
# define LEN_H		0x2
# define LEN_HH		0x4
# define LEN_L		0x8
# define LEN_LL		0x10

# define PLUS		0x1
# define MINUS		0x2
# define SPACE		0x4
# define ZERO		0x8
# define SHARP		0x10

# define CHARMAX	0x7fU
# define SHORTMAX	0x7fffU
# define INTMAX		0x7fffffffU
# define LONGMAX	0x7fffffffffffffffUL

# define FT_INF32_P	0x7f800000U
# define FT_INF32_N	0xff800000U
# define FT_INF64_P	0x7ff0000000000000UL
# define FT_INF64_N	0xfff0000000000000UL

typedef	unsigned long int	t_longword;
typedef	unsigned char		t_byte;
typedef unsigned short		t_ushort;
typedef	int					t_bool;
typedef	unsigned long		t_ulong;
typedef	unsigned int		t_uint;
typedef unsigned long long	t_ullong;

typedef struct	s_opt
{
	int		flag;
	int		width;
	int		precision;
	int		length;
	int		cast;
}				t_opt;

int				ft_printf(const char *fmt, ...);
int				print_conv(const char **string, t_opt *o, va_list ap);

void			get_sign(t_opt *o, int neg, char *sign);
int				print_number_with_options(char *n, t_opt *o, int neg);

int				get_specifier(const char **s, t_opt *o, va_list ap);
int				c_specifier(int c, t_opt *o);
int				x_specifier(t_ullong n, t_opt *o);
int				p_specifier(t_ullong n, t_opt *o);
int				xmaj_specifier(t_ullong n, t_opt *o);
int				s_specifier(const char *s, t_opt *o);
int				u_specifier(t_ullong n, t_opt *o);
int				di_specifier(long long n, t_opt *o);
int				b_specifier(t_ullong n, t_opt *o);
int				v_specifier(double n, t_opt *o);
int				w_specifier(long double n, t_opt *o);
int				o_specifier(t_ullong n, t_opt *o);
int				y_specifier(void *ptr, t_opt *o, const char **fmt);
int				f_specifier(double n, t_opt *o);
int				lf_specifier(long double n, t_opt *o);

int				get_left_zero_count(t_ulong decimal);
int				ft_isnan_or_isinf(t_ulong n, size_t size);
int				ft_isinf(t_ulong n, size_t size);

int				ft_strlen(const char *str);
char			*ft_strncpy(char *s1, const char *s2, size_t l);
int				ft_strncmp(const char *s1, const char *s2, size_t l);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memrcpy(void *dst, const void *src, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *dst, const char *src);
int				ultoa_buf(t_ulong n, char *buf);
char			*ft_strchr(const char *s, int n);
int				ft_strnlen(const char *str, unsigned int n);
int				ft_isdigit(int c);
t_ulong			ft_ten_powul(int p);

#endif
