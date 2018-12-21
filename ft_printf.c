/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 18:24:26 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 10:36:50 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Usage
**
**	-b (hh, h, l, ll, z, j, ...)	: affiche un entier en base 2
**	-c								: affiche un caractere
**	-d (hh, h, l, ll, z, j, ...)	: affiche un entier en base 10
**	-f (L, l)						: affiche un flottant en base 10
**	-i								: -d
**	-n (hh, h, l, ll, z, j, ...)	: enregistre le nb de caracteres ecrits
**									  dans le pointeur passe en argument
**	-o (hh, h, l, ll, z, j, ...)	: affiche un entier en base 8
**	-p								: affiche l'adresse d'un ptr en base 16
**	-s								: affiche une chaine de caracteres
**	-u (hh, h, l, ll, z, j, ...)	: affiche un entier non-signe
**	-v (l, L)						: affiche un flottant en binaire
**	-Z								: affiche un tableau de chaines
**	-y (hh, h, l, ll, z, j, ...)	: affiche un tableau signe
**	-Y (hh, h, l, ll, z, j, ...)	: affiche un tableau non-signe
**	-w								: affiche une structure
**		exemple -> "%zint,int,next;"
**		types acceptes :
**			char, uchar, short, ushort, int, uint, long, ulong, llong, ullong,
**			char*, char[], void*, *void{...}, struct{...}, next,
**			pad[0-9]+, pad_[type]
*/

inline int			ft_printf(const char *fmt, ...)
{
	const char	*org = fmt;
	int			tmp;
	va_list		ap;
	t_opt		o;

	va_start(ap, fmt);
	o.curlen = 0;
	while ((fmt = ft_strchr(fmt, '%')) != NULL)
	{
		++fmt;
		if ((tmp = fmt - org - 1))
			o.curlen += write(1, org, tmp);
		o.curlen += print_conv((const t_byte**)&fmt, &o, ap);
		org = ++fmt;
	}
	va_end(ap);
	fmt = org + ft_strlen(org);
	return (o.curlen + write(1, org, fmt - org));
}
