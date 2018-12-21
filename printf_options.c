/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   _=+/'''''''''\+=_                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: FCORDON <101@le-101.101>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 1992/02/24 01:46:29 by FCORDON      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 20:22:46 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "call.h"

static void			set_flag(const t_byte **s, t_opt *o)
{
	static const int		flag[49] = {
		SPACE, 0, 0, SHARP, 0, 0, 0, 0,
		0, 0, 0, PLUS, 0, MINUS, 0, 0, ZERO
	};
	register unsigned int	c;

	o->flag = 0;
	while ((c = (**s - 32)) < 17 && flag[c])
	{
		o->flag |= flag[c];
		(*s)++;
	}
}

static void			set_length(const t_byte **s, t_opt *o)
{
	static const int		length[47] = {
		L_LMAJ, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, L_H, 0,
		L_J, 0, L_L, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, L_Z
	};
	register unsigned int	c;

	o->length = 0;
	while ((c = (**s - 76)) < 47 && length[c])
	{
		if ((*s)[1] == **s && (length[c] == L_L || length[c] == L_H))
		{
			o->length = length[c] + 1;
			*s += 2;
		}
		else
		{
			o->length = length[c];
			(*s)++;
		}
	}
}

static int			get_numerical_value(const t_byte **s, int default_v)
{
	const t_byte	*p = *s;
	t_uint			tmp;

	if (!ft_isdigit(*p))
		return (default_v);
	tmp = 0;
	while (1)
	{
		tmp *= 10;
		tmp += *p - 48;
		if (!ft_isdigit(*(++p)))
			break ;
	}
	*s = p;
	return (tmp);
}

extern inline int	print_conv(const t_byte **string,
								t_opt *options, va_list ap)
{
	set_flag(string, options);
	if (**string == '*')
	{
		options->width = va_arg(ap, int);
		if (options->width < -1)
			options->width = -1;
		(*string)++;
	}
	else
		options->width = get_numerical_value(string, -1);
	options->precision = -1;
	if (**string == '.')
	{
		if (*(++(*string)) == '*')
		{
			options->precision = va_arg(ap, int);
			if (options->precision < -1)
				options->precision = -1;
			(*string)++;
		}
		else
			options->precision = get_numerical_value(string, 0);
	}
	set_length(string, options);
	return (call_convertion_function(string, options, ap));
}
