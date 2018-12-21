/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   y_specifier.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 15:31:31 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 18:46:22 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "w_print_member.h"
#include "w_global.h"
#include "../ft_printf.h"

const char			*g_wtype[TYPECOUNT] = {
	"char[]", "char*", "char", "short", "int", "long double", "long long",
	"long", "llong", "size_t", "ssize_t", "intmax_t", "void*", "float",
	"double", "ldouble"
};

const int			g_wlen[TYPECOUNT] = {
	6, 5, 4, 5, 3, 11, 9, 4, 5, 6, 7, 8, 5, 5, 6, 7
};

const t_print		g_wprint[TYPECOUNT] = {
	print_direct_str, print_str, print_char, print_short, print_int,
	print_ldouble, print_llong, print_long, print_llong, print_size_t,
	print_ssize_t, print_intmax_t, print_ptr, print_float, print_double,
	print_ldouble
};

static int			is_next_or_pad(const char **fmt)
{
	if (!strncmp(*fmt, "next", 4))
	{
		*fmt += 4;
		if (**fmt != ',' && **fmt != ';')
			return (0);
		return (1);
	}
	else if (!strncmp(*fmt, "pad", 3))
	{
		*fmt += 3;
		while (**fmt != ',' && **fmt != ';')
			(*fmt)++;
		return (1);
	}
	return (0);
}

static int			is_recognized_type(const char **fmt)
{
	int					i;

	if (**fmt == 'u')
		(*fmt) += (!strncmp(*fmt + 1, "nsigned ", 8)) ? 9 : 1;
	i = 0;
	while (i < TYPECOUNT)
	{
		if (!strncmp(*fmt, g_wtype[i], g_wlen[i]))
		{
			*fmt += g_wlen[i];
			return (1);
		}
		i++;
	}
	return (is_next_or_pad(fmt));
}

extern int			valid_wfmt(const char *fmt)
{
	while (*fmt)
	{
		if (!is_recognized_type(&fmt))
			return (write(1, "[ERROR_NO_RECOGNIZED_TYPE]", 26));
		if (*fmt == '=')
		{
			fmt++;
			if (!isalpha(*fmt) && *fmt != '_')
				return (write(1, "[ERROR_BAD_NAME_MEMBER]", 23));
			while (*(++fmt) != ',' && *fmt != ';')
			{
				if (!isalpha(*fmt) && !isdigit(*fmt) && *fmt != '_')
					return (write(1, "[ERROR_BAD_NAME_MEMBER]", 23));
			}
		}
		if (*fmt == ';')
			break ;
		else if (*fmt != ',')
			return (write(1, "[ERROR_FORGOT_ENDCHAR_OR_INVALID_TYPE]", 38));
		fmt++;
	}
	return (0);
}

extern int			w_spe(void *ptr, t_opt *o, const char **fmt)
{
	int			count;
	t_ydata		p;

	if (o->width == 0)
		return (0);
	if ((count = valid_wfmt(*fmt + 1)) != 0)
		return (count);
	count += write(1, "\n", 1);
	p.start = *fmt + 1;
	p.s = *fmt + 1;
	p.next = NULL;
	p.offset = 0;
	p.n_elem = o->width;
	p.ptr = ptr;
	*fmt = print_data(p, &count) - 1;
	return (count);
}
