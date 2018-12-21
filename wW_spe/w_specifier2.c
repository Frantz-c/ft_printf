/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   w_specifier2.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 18:43:53 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 18:47:10 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "w_print_member.h"
#include "w_global.h"
#include "../ft_printf.h"

static inline int			set_next_ptr(int *offset, void *ptr, void **next)
{
	*offset += get_padding(*offset, sizeof(void**));
	*next = *(void**)(ptr + *offset);
	*offset += sizeof(void**);
	return (5);
}

static inline int			print_printable_member(const char **s,
		int *offset, void *ptr, int u)
{
	int		i;
	int		count;

	i = 0;
	while (i < TYPECOUNT)
	{
		if (!strncmp(*s, g_wtype[i], g_wlen[i]))
		{
			(*s) += g_wlen[i];
			count = (g_wprint[i](offset, s, ptr, u));
			return (count);
		}
		i++;
	}
	return (0);
}

static int					loop_continue(t_ydata *d, int *count)
{
	d->offset = 0;
	if (d->next)
	{
		if (--d->n_elem == 0)
		{
			*count += write(1, "[end]\n", 6);
			return (0);
		}
		d->ptr = d->next;
		d->next = NULL;
		*count += write(1, "[next]\n\n", 8);
		d->s = d->start;
	}
	else
	{
		*count += write(1, "[end]\n", 6);
		return (0);
	}
	return (1);
}

static int					is_unsigned_type(const char **s)
{
	if (**s == 'u')
	{
		*s += (!ft_strncmp(*s + 1, "nsigned ", 8)) ? 9 : 1;
		return (1);
	}
	return (0);
}

extern inline const char	*print_data(t_ydata d, int *count)
{
	int		tmp;

	while (1)
	{
		d.u = is_unsigned_type(&d.s);
		if (!ft_strncmp(d.s, "*void", 5))
		{
			call_recursive(&d, count);
			continue ;
		}
		else if ((tmp = print_printable_member(&d.s, &d.offset, d.ptr, d.u)))
			*count += tmp;
		else if (!ft_strncmp(d.s, "pad", 3))
			d.s += padding(d.s + 3, &d.offset);
		else if (!ft_strncmp(d.s, "next", 4))
			d.s += set_next_ptr(&d.offset, d.ptr, &d.next);
		else
			break ;
		if (d.s[-1] == '}')
			return (d.s);
		else if (d.s[-1] == ';' && !loop_continue(&d, count))
			break ;
	}
	return (d.s);
}
