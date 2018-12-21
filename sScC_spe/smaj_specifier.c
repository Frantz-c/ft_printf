/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   smaj_specifier.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 14:27:18 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 10:46:22 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_printf.h"

static int			wchar_len(const wchar_t *s)
{
	const wchar_t *start = s;

	while (*s)
		s++;
	return ((t_ulong)s - (t_ulong)start);
}

/*
**	calcul le nombre d'octets attendus dans le caractere actuel.
**	retourne la longueur de la chaine jusau'au dernier caractere entier
**	ou 0 si on est pas sur le premier octet du caractere.
**	(n = nombre d'octets attendus apres le premier)
*/

static int			get_new_length(char *utf8, int len, int n, const int end)
{
	if (utf8[len] & 0x80 && utf8[len] & 0x40)
	{
		if (utf8[len] & 0x20)
		{
			if (utf8[len] & 0x10)
				n = 3;
			else
				n = 2;
		}
		else
			n = 1;
	}
	if (n)
	{
		if (n != (end - len - 1))
			return (len);
		else
			return ((int)end);
	}
	return (0);
}

static inline int	cut_properly(char *utf8, int len)
{
	const int	end = len;
	int			ret;

	if (!(utf8[len - 1] & 0x80))
		return (len);
	len--;
	ret = 0;
	while (len > 0)
	{
		if ((ret = get_new_length(utf8, len, 0, end)) != 0)
			return (ret);
		len--;
	}
	return (0);
}

static int			str_unicode_to_utf8(char **utf8, const wchar_t *s, t_opt *o)
{
	char	*new;
	int		tmp;
	int		len;

	if (!s)
	{
		*utf8 = malloc(7);
		ft_strcpy(*utf8, "(null)");
		return (6);
	}
	new = malloc((wchar_len(s) * 2) + 2);
	*utf8 = new;
	len = 0;
	while (*s)
	{
		tmp = unicode_to_utf8(*s, new);
		len += tmp;
		new += tmp;
		s++;
	}
	*new = '\0';
	if (o->precision > -1)
		len = o->precision < len ? o->precision : len;
	return ((o->precision == -1) ? len : cut_properly(*utf8, len));
}

extern int			smaj_spe(const wchar_t *s, t_opt *o)
{
	char		*utf8;
	const int	len = str_unicode_to_utf8(&utf8, s, o);
	int			ret;

	ret = 0;
	while (o->width > len)
	{
		o->width -= len;
		if (o->flag & MINUS)
		{
			ret = write(1, utf8, len) + o->width;
			while (o->width--)
				write(1, " ", 1);
			free(utf8);
			return (ret);
		}
		o->length = (o->flag & ZERO) ? '0' : ' ';
		ret = o->width;
		while (o->width--)
			write(1, &o->length, 1);
		break ;
	}
	ret += write(1, utf8, len);
	free(utf8);
	return (ret);
}
