/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   z_specifier.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 18:36:21 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 18:48:53 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "y_print.h"
#include "../ft_printf.h"

static void			set_start(char *fmt, t_opt *o)
{
	if (o->flag & SHARP)
		ft_strcpy(fmt, "[%d] = ");
	else
		fmt[0] = '\0';
	(o->precision == 2) ? ft_strcat(fmt, "% ") : ft_strcat(fmt, "%");
}

static void			set_length(char *fmt, t_opt *o)
{
	if (o->length == L_LL)
		ft_strcat(fmt, "ll");
	if (o->length == L_L)
		ft_strcat(fmt, "l");
	if (o->length == L_H)
		ft_strcat(fmt, "h");
	if (o->length == L_HH)
		ft_strcat(fmt, "hh");
	if (o->length == L_Z)
		ft_strcat(fmt, "z");
	if (o->length == L_J)
		ft_strcat(fmt, "j");
}

static void			set_specifier(char *fmt, t_opt *o)
{
	if (o->precision == 2)
		(o->flag & SHARP) ? ft_strcat(fmt, "b\n") : ft_strcat(fmt, "b");
	else if (o->precision == 8)
		(o->flag & SHARP) ? ft_strcat(fmt, "o\n") : ft_strcat(fmt, "o");
	else if (o->precision == 16)
		(o->flag & SHARP) ? ft_strcat(fmt, "x\n") : ft_strcat(fmt, "x");
	else
		(o->flag & SHARP) ? ft_strcat(fmt, "u\n") : ft_strcat(fmt, "u");
}

extern inline int	ymaj_spe(void *t, t_opt *o)
{
	char	fmt[32];

	if (!t)
		return (write(1, "[null]", 6));
	if (o->width < 1)
		return (0);
	set_start(fmt, o);
	set_length(fmt, o);
	set_specifier(fmt, o);
	return (print_array(fmt, t, o));
}
