/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   z_print_member3.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 10:57:34 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 18:14:54 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "w_print_member.h"

extern inline int	print_llong(int *off, const char **s, void *ptr, int u)
{
	int		count;
	char	*p;

	*off += get_padding(*off, sizeof(long long));
	if (**s == '=')
	{
		if ((p = ft_strchr(*s + 1, ',')) == NULL)
			p = ft_strchr(*s + 1, ';');
		count = (u) ? ft_printf("(ulong )%.*s = %llu\n",
							(p - *s - 1), *s + 1, *(t_ullong*)(ptr + *off)) :
					ft_printf("(long  )%.*s = %lld\n",
							(p - *s - 1), *s + 1, *(long long*)(ptr + *off));
		(*s) += (p - *s);
	}
	else
		count = (u) ? ft_printf("[ullong] = %llu\n",
								*(t_ullong*)(ptr + *off)) :
					ft_printf("[llong ] = %lld\n", *(long long*)(ptr + *off));
	*off += sizeof(long long);
	(*s)++;
	return (count);
}

inline int			print_size_t(int *offset, const char **s, void *ptr, int u)
{
	int		count;
	char	*p;

	(void)u;
	*offset += get_padding(*offset, sizeof(size_t));
	if (**s == '=')
	{
		if ((p = ft_strchr(*s + 1, ',')) == NULL)
			p = ft_strchr(*s + 1, ';');
		count = ft_printf("(size_t)%.*s = %zu\n",
						(int)(p - *s - 1), *s + 1, *(size_t*)(ptr + *offset));
		(*s) += (int)(p - *s);
	}
	else
		count = ft_printf("[size_t] = %u\n", *(size_t*)(ptr + *offset));
	*offset += sizeof(size_t);
	(*s)++;
	return (count);
}

inline int			print_ssize_t(int *offset, const char **s, void *ptr, int u)
{
	int		count;
	char	*p;

	(void)u;
	*offset += get_padding(*offset, sizeof(ssize_t));
	if (**s == '=')
	{
		if ((p = ft_strchr(*s + 1, ',')) == NULL)
			p = ft_strchr(*s + 1, ';');
		count = ft_printf("(ssize_t)%.*s = %zu\n",
						(int)(p - *s - 1), *s + 1, *(ssize_t*)(ptr + *offset));
		(*s) += (int)(p - *s);
	}
	else
		count = ft_printf("[ssize_t] = %u\n", *(ssize_t*)(ptr + *offset));
	*offset += sizeof(ssize_t);
	(*s)++;
	return (count);
}

inline int			print_intmax_t(int *offst, const char **s, void *ptr, int u)
{
	int		count;
	char	*p;

	*offst += get_padding(*offst, sizeof(int));
	if (**s == '=')
	{
		if ((p = ft_strchr(*s + 1, ',')) == NULL)
			p = ft_strchr(*s + 1, ';');
		count = (u) ? ft_printf("(uintmax_t)%.*s = %u\n",
					(int)(p - *s - 1), *s + 1, *(uintmax_t*)(ptr + *offst)) :
					ft_printf("(intmax_t)%.*s = %d\n",
					(int)(p - *s - 1), *s + 1, *(intmax_t*)(ptr + *offst));
		(*s) += (int)(p - *s);
	}
	else
		count = (u) ? ft_printf("[uintmax_t] = %u\n",
								*(uintmax_t*)(ptr + *offst)) :
					ft_printf("[intmax_t] = %d\n",
								*(intmax_t*)(ptr + *offst));
	*offst += sizeof(intmax_t);
	(*s)++;
	return (count);
}
