/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   call_convertion_function.c                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 16:41:41 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 16:38:19 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
**	MODE D'EMPLOI
**
**	Ajout d'une fonction:
**
**		A) type entier < ou = long long max avec length variable (l, h, ...)
**
**			1) Ajouter la fonction au tableau g_function[58] = {A-Zxxxxxxa-z}
**			2) Ajouter le bit 1 (0x1) a l'element ([specifier] - 65)
**				du tableau g_functype[58] = {A-Zxxxxxxa-z} si
**				la fonction prend un nombre non-signe.
**
**		B) type flottant avec 2 fonctions (float/double, long double)
**			et length variable (l, L)
**
**			1) Ajouter la fonction float/double
**				au tableau g_function[58] = {A-Zxxxxxxa-z}
**			2) Ajouter la fonction long double au tableau
**				g_ldfunc[58] = {A-Zxxxxxxa-z}
**			3) Ajouter le bit 2 (0x2) a l'element ([specifier] - 65)
**				du tableau g_functype[58] = {A-Zxxxxxxa-z}
**
**		C) fonctions avec length non variables et/ou au prototype different
**
**			1) Ajouter la fonction au tableau g_function[58] = {A-Zxxxxxxa-z}
**			2) Ajouter la fonction d'appel au tableau
**				fixed_len_convertion::type[58] = {A-Zxxxxxxa-z}
**				si le prototype est {int (type, t_opt *)}
**									ou
**				rajouter une condition qui appelle la nouvelle fonction
**				a la fin de la fonction fixed_len_comvertion
*/

#include "ft_printf.h"
#include "call.h"

/*
**	Tableau de pointeurs sur fonctions
*/

static const t_voidf	g_function[58] =
{
	0, 0, (t_vf)cmaj_spe, (t_vf)di_spe, 0, (t_vf)f_spe, 0, 0, (t_vf)di_spe,
	0, 0, 0, 0, 0, (t_vf)o_spe, 0, 0, 0, (t_vf)smaj_spe, 0, (t_vf)u_spe, 0,
	(t_vf)wmaj_spe, (t_vf)xmaj_spe, (t_vf)ymaj_spe, (t_vf)zmaj_spe,
	0, 0,
	0, 0,
	0, 0,
	0, (t_vf)b_spe, (t_vf)c_spe, (t_vf)di_spe, 0, (t_vf)f_spe, 0, 0,
	(t_vf)di_spe, 0, 0, 0, 0, (t_vf)n_spe, (t_vf)o_spe, (t_vf)p_spe, 0, 0,
	(t_vf)s_spe, 0, (t_vf)u_spe, (t_vf)v_spe, 0, (t_vf)x_spe, (t_vf)y_spe, 0,
};

/*
**	Tableau de pointeur sur la version long double
**	des fonctions sur les flottants
*/

static const t_voidf	g_ldfunc[58] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, (t_vf)lf_spe, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, (t_vf)lv_spe, 0, 0, 0, 0
};

static const t_uint		g_functype[58] =
{
	0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 8, 1, 1, 0, 0, 0, 0, 0, 0,
	0, 8, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
	1, 8, 9, 0, 0, 1, 0, 8, 2, 1, 8, 1, 0
};

/*
**	fixed_len_convertion:
**		appelle les conversions qui n'utilisent pas [length]
**	variable_len_convertion:
**		appelle les conversions d'entiers utilisants [length]
**	variable_len_float_conv:
**		appelle les conversions de flottants utilisants [length]
*/

static inline int		fixed_len_convertion(const t_byte **s, t_opt *o,
								va_list ap, t_uint c)
{
	static const t_call	types[58] = {
		0, 0, call_wchar_t_fl, call_long, 0, call_double, 0, 0, call_long,
		0, 0, 0, 0, 0, call_ulong_fl, 0, 0, 0, call_ptr, 0, call_ulong,
		0, 0, 0, call_ptr, call_ptr,
		0, 0,
		0, 0,
		0, 0,
		0, 0, call_int_fl, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, call_ptr, 0,
		call_ptr, 0, 0, call_ptr, 0, 0, 0, 0, 0, call_ptr, 0
	};

	if (types[c])
		return (types[c](g_function[c], o, ap));
	if (c == 54)
		return (w_spe(va_arg(ap, void*), o, (const char **)s));
	if (c == 22)
		return (wmaj_spe(va_arg(ap, void*), o, (const char **)s));
	return (0);
}

static inline int		variable_len_float_conv(const t_byte c, t_opt *o,
										va_list ap)
{
	if (o->length == L_LMAJ && g_ldfunc[c])
		return (call_ldouble(g_ldfunc[c], o, ap));
	if (o->length == L_L && g_function[c])
		return (call_double(g_function[c], o, ap));
	if (o->length == 0 && g_function[c])
		return (call_float(g_function[c], o, ap));
	return (0);
}

static int				variable_len_convertion(const t_byte c, t_opt *o,
										va_list ap)
{
	static const t_call		scall[L_MAX + 2] = {
		call_int, call_ldouble, call_long, call_llong,
		call_short, call_char, call_ssize_t, call_intmax_t, call_double
	};
	static const t_call		ucall[L_MAX + 1] = {
		call_uint, 0, call_ulong, call_ullong,
		call_ushort, call_uchar, call_size_t, call_uintmax_t
	};

	if (g_function[c] == 0)
		return (0);
	if (g_functype[c] & IS_UNSIGNED_FUNCTION)
		return (ucall[o->length](g_function[c], o, ap));
	return (scall[o->length](g_function[c], o, ap));
}

/*
**	Routeur de conversions, apres traitement des options.
*/

extern inline int		call_convertion_function(const t_byte **s,
								t_opt *options, va_list ap)
{
	register unsigned int	c;

	if (**s == '%')
	{
		options->precision = -1;
		return (print_string_with_options("%", options, 1));
	}
	if ((c = (t_byte)(**s - 65)) > 57)
		return (0);
	if (g_functype[c] & LENGTH_NOT_EXPECTED)
		return (fixed_len_convertion(s, options, ap, c));
	if (g_functype[c] & VLEN_FLOAT_EXPECTED)
		return (variable_len_float_conv(c, options, ap));
	return (variable_len_convertion(c, options, ap));
}
