/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   y_functions.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 11:11:12 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:40:49 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "w_print_member.h"

extern int			get_padding(int addr, size_t size)
{
	if (addr % size)
		return (size - (addr % size));
	return (0);
}

static int			skip_member_digits(int *addr, const char *s)
{
	int	i;
	int	off;

	i = 0;
	off = 0;
	while (ft_isdigit(s[i]))
	{
		off *= 10;
		off += s[i] - 48;
		i++;
	}
	*addr += off;
	return (i);
}

static inline int	skip_member(int *addr, size_t size)
{
	*addr += get_padding(*addr, size) + size;
	return (0);
}

extern inline int	padding(const char *s, int *offset)
{
	if (ft_isdigit(*s))
		return (skip_member_digits(offset, s) + 4);
	else if (!ft_strncmp(s, "_char", 5))
		return (skip_member(offset, sizeof(char)) + 9);
	else if (!ft_strncmp(s, "_short", 6))
		return (skip_member(offset, sizeof(short)) + 10);
	else if (!ft_strncmp(s, "_int", 4))
		return (skip_member(offset, sizeof(int)) + 8);
	else if (!ft_strncmp(s, "_float", 6))
		return (skip_member(offset, sizeof(float)) + 10);
	else if (!ft_strncmp(s, "_long", 5))
		return (skip_member(offset, sizeof(long)) + 9);
	else if (!ft_strncmp(s, "_double", 7))
		return (skip_member(offset, sizeof(double)) + 11);
	else if (!ft_strncmp(s, "_long_double", 12))
		return (skip_member(offset, sizeof(t_ld)) + 16);
	else if (!ft_strncmp(s, "_ptr", 4))
		return (skip_member(offset, sizeof(void*)) + 8);
	return (4);
}

extern void			call_recursive(t_ydata *d, int *count)
{
	t_ydata		new;

	d->offset += get_padding(d->offset, sizeof(void*));
	d->s += 6;
	new = *d;
	new.ptr = *(void**)(new.ptr + new.offset);
	d->s = print_data(new, count);
	d->offset += sizeof(void*);
}
