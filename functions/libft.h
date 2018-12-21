/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 17:58:16 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 11:07:14 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef	unsigned long int	t_longword;
typedef	unsigned char		t_byte;
typedef unsigned short		t_ush;
typedef unsigned short		t_ushort;
typedef	int					t_bool;
typedef	unsigned long		t_ulong;
typedef	unsigned int		t_uint;
typedef unsigned long long	t_ullong;
typedef long double			t_ld;

extern int		ft_isdigit(int c);
extern char		*strjoin_path(const char *s1, const char *s2);
extern char		*ft_strjoin(const char *s1, const char *s2);
extern int		ultoa_buf(t_ulong n, char *buf);
extern void		*ft_memcpy(void *dst, const void *src, size_t len);
extern void		*ft_memmove(void *dst, const void *src, size_t n);
extern void		*ft_memrcpy(void *dst, const void *src, size_t len);
extern void		*ft_memset(void *s, int c, size_t n);
extern int		is_space(char c);
extern char		*skip_spaces(const char *s);
extern char		*ft_strcat(char *dst, const char *src);
extern char		*ft_strchr(const char *s, int int_c);
extern char		*ft_strcpy(char *dst, const char *src);
extern int		ft_strlen(const char *str);
extern int		ft_strncmp(const char *s1, const char *s2, size_t n);
extern char		*ft_strncpy(char *dst, const char *src, size_t n);
extern int		ft_strnlen(const char *str, t_uint max);
extern t_ulong	ft_ten_powul(int p);
extern char		*ft_strstr(const char *str, const char *sub);
extern void		*ft_memchr(const void *str, int c, size_t n);
extern char		*ft_strndup(const char *s, size_t len);
extern void		*free_arg1_arg2_and_return_arg3(void *a1, void *a2, void *a3);
extern void		assign_null_2a(void **a1, void **a2);
extern int		get_next_line(const int fd, char **line);
extern char		*ft_strncat(char *dst, const char *src, size_t n);
extern char		*ft_strdup(const char *s);
extern int		ft_strcmp(const char *s1, const char *s2);

#endif
