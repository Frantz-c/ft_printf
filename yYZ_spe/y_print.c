/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   y_print.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 13:53:33 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 16:20:21 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

static int			print_with_cast_sharp(char *fmt, void *t, t_opt *o, int i)
{
	if (o->length == L_LL)
		return (ft_printf(fmt, i, ((long long*)t)[i]));
	if (o->length == L_L)
		return (ft_printf(fmt, i, ((long*)t)[i]));
	if (o->length == L_H)
		return (ft_printf(fmt, i, ((short*)t)[i]));
	if (o->length == L_HH)
		return (ft_printf(fmt, i, ((char*)t)[i]));
	if (o->length == L_Z)
		return (ft_printf(fmt, i, ((ssize_t*)t)[i]));
	if (o->length == L_J)
		return (ft_printf(fmt, i, ((intmax_t*)t)[i]));
	return (ft_printf(fmt, i, ((int*)t)[i]));
}

static int			print_with_cast(char *fmt, void *t, t_opt *o, int i)
{
	if (o->length == L_LL)
		return (ft_printf(fmt, ((long long*)t)[i]));
	if (o->length == L_L)
		return (ft_printf(fmt, ((long*)t)[i]));
	if (o->length == L_H)
		return (ft_printf(fmt, ((short*)t)[i]));
	if (o->length == L_HH)
		return (ft_printf(fmt, ((char*)t)[i]));
	if (o->length == L_Z)
		return (ft_printf(fmt, ((ssize_t*)t)[i]));
	if (o->length == L_J)
		return (ft_printf(fmt, ((intmax_t*)t)[i]));
	return (ft_printf(fmt, ((int*)t)[i]));
}

extern inline int	print_array(char *fmt, void *t, t_opt *o)
{
	int		i;
	int		ret;

	i = 0;
	if (o->flag & SHARP)
	{
		ret = write(1, "\n", 1);
		while (i < o->width)
		{
			ret += print_with_cast_sharp(fmt, t, o, i);
			i++;
		}
		return (ret);
	}
	ret = write(1, "{", 1);
	while (i < o->width)
	{
		if (i)
			ret += write(1, ", ", 2);
		ret += print_with_cast(fmt, t, o, i);
		i++;
	}
	ret += write(1, "}", 1);
	return (ret);
}
