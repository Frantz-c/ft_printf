/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 18:24:26 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 15:10:52 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

inline int			ft_printf(const char *fmt, ...)
{
	const char	*org = fmt;
	int			length;
	int			tmp;
	va_list		ap;
	t_opt		options;

	va_start(ap, fmt);
	length = 0;
	while ((fmt = ft_strchr(fmt, '%')) != NULL)
	{
		++fmt;
		if ((tmp = fmt - org - 1))
			length += write(1, org, tmp);
		length += print_conv(&fmt, &options, ap);
		org = fmt;
	}
	va_end(ap);
	fmt = org + ft_strlen(org);
	return (length + write(1, org, fmt - org));
}
