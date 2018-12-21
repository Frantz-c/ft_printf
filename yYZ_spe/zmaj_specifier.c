/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   t_specifier.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 17:29:36 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:47:42 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

static int			width_and_precision(char **t, t_opt *o)
{
	int		i;
	int		ret;

	i = 0;
	ret = write(1, "\n", 1);
	while (t[i] && i < o->width)
	{
		if (o->flag & SHARP)
			ret += ft_printf("[%d] = %.*s\n", i, o->precision, t[i]);
		else
			ret += ft_printf("%.*s\n", o->precision, t[i]);
		i++;
	}
	return (ret);
}

static int			only_width(char **t, t_opt *o)
{
	int		i;
	int		ret;

	i = 0;
	ret = write(1, "\n", 1);
	while (t[i] && i < o->width)
	{
		if (o->flag & SHARP)
			ret += ft_printf("[%d] = %s\n", i, t[i]);
		else
			ret += ft_printf("%s\n", t[i]);
		i++;
	}
	return (ret);
}

static int			only_precision(char **t, t_opt *o)
{
	int		i;
	int		ret;

	i = 0;
	ret = write(1, "\n", 1);
	while (t[i])
	{
		if (o->flag & SHARP)
			ret += ft_printf("[%d] = %.*s\n", i, o->precision, t[i]);
		else
			ret += ft_printf("%.*s\n", o->precision, t[i]);
		i++;
	}
	return (ret);
}

static int			no_width_no_precision(char **t, t_opt *o)
{
	int		i;
	int		ret;

	i = 0;
	ret = write(1, "\n", 1);
	while (t[i])
	{
		if (o->flag & SHARP)
			ret += ft_printf("[%d] = %s\n", i, t[i]);
		else
			ret += ft_printf("%s\n", t[i]);
		i++;
	}
	return (ret);
}

extern inline int	zmaj_spe(char **t, t_opt *o)
{
	if (o->width == 0 || o->precision == 0)
		return (0);
	if (!t)
		return (write(1, "[null]", 6));
	if (!*t)
		return (write(1, "[->null]", 8));
	if (o->width != -1)
	{
		if (o->precision != -1)
			return (width_and_precision(t, o));
		return (only_width(t, o));
	}
	if (o->precision != -1)
		return (only_precision(t, o));
	return (no_width_no_precision(t, o));
}
