/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   _=+/'''''''''\+=_                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: FCORDON <101@le-101.101>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 1992/02/24 01:46:29 by FCORDON      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 18:08:56 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int			get_hhll(const char **p, int *length)
{
	if (**p == 'h')
	{
		*length &= 0xf9;
		if ((*p)[1] == 'h')
		{
			*length |= LEN_HH;
			(*p)++;
		}
		else
			*length |= LEN_H;
	}
	else if (**p == 'l')
	{
		*length &= 0xe7;
		if ((*p)[1] == 'l')
		{
			*length |= LEN_LL;
			(*p)++;
		}
		else
			*length |= LEN_L;
	}
	else
		return (0);
	return (1);
}

static inline void	get_length(const char **s, int *length)
{
	const char	*p = *s;

	*length = 0;
	while (1)
	{
		if (*p == 'L')
			*length |= LEN_LF;
		else if (!get_hhll(&p, length))
			break ;
		p++;
	}
	*s = p;
	if (*length & 0x18)
		*length &= 0xf9;
	else if (*length & 0x6)
		*length &= 0xe7;
}

static void			get_flag(const char **s, int *flag)
{
	int	c;

	*flag = 0;
	while (1)
	{
		if ((c = **s) == '+')
			*flag |= PLUS;
		else if (c == '-')
			*flag |= MINUS;
		else if (c == ' ')
			*flag |= SPACE;
		else if (c == '0')
			*flag |= ZERO;
		else if (c == '#')
			*flag |= SHARP;
		else
			break ;
		(*s)++;
	}
}

static void			get_width(const char **s, int *width)
{
	const char	*p = *s;
	t_uint		tmp;

	if (!ft_isdigit(*p))
	{
		*width = -1;
		return ;
	}
	tmp = 0;
	while (ft_isdigit(*p))
	{
		tmp *= 10;
		tmp += *p - 48;
		p++;
	}
	*width = tmp;
	*s = p;
}

extern inline int	print_conv(const char **string, t_opt *options, va_list ap)
{
	get_flag(string, &options->flag);
	if (**string == '*')
	{
		options->width = va_arg(ap, int);
		(*string)++;
	}
	else
		get_width(string, &options->width);
	options->precision = -1;
	if (**string == '.')
	{
		if (*((*string)++) == '*')
		{
			options->precision = va_arg(ap, int);
			(*string)++;
		}
		else
			get_width(string, &options->precision);
	}
	get_length(string, &options->length);
	return (get_specifier(string, options, ap));
}
