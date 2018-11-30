/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   integer_print.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 14:00:24 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 16:09:33 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	width_only(char *n, t_opt *o, char *sign, const int len)
{
	char	fill;
	int		ret;
	int		sign_len;

	sign_len = (*sign != 0) + (sign[1] != 0);
	ret = (len + sign_len > o->width) ?
			len + sign_len : o->width;
	fill = (o->flag & ZERO && !(o->flag & MINUS)) ? '0' : ' ';
	o->width -= sign_len;
	if (fill == '0' && sign_len)
		write(1, sign, sign_len);
	if (!(o->flag & MINUS))
	{
		while (o->width-- > len)
			write(1, &fill, 1);
	}
	if (fill != '0' && sign_len)
		write(1, sign, sign_len);
	write(1, n, len);
	if (o->flag & MINUS)
	{
		while (o->width-- > len)
			write(1, &fill, 1);
	}
	return (ret);
}

static int	width_and_precision(char *n, t_opt *o, char *sign, const int len)
{
	int		ret;
	int		sign_len;

	sign_len = (*sign != 0) + (sign[1] != 0);
	ret = o->width > o->precision + sign_len ?
			o->width : o->precision + sign_len;
	if (o->precision < len)
		o->precision = len;
	o->width -= o->precision + sign_len;
	if (!(o->flag & MINUS))
	{
		while (o->width-- > 0)
			write(1, " ", 1);
	}
	if (sign_len)
		write(1, sign, sign_len);
	while (o->precision-- > len)
		write(1, "0", 1);
	write(1, n, len);
	if (o->flag & MINUS)
		while (o->width-- > 0)
			write(1, " ", 1);
	return (ret);
}

static int	no_width_no_precision(char *n, char *sign, const int len)
{
	int		ret;
	int		sign_len;

	sign_len = (*sign != 0) + (sign[1] != 0);
	ret = 0;
	if (sign_len)
		ret = write(1, sign, sign_len);
	return (ret + write(1, n, len));
}

static int	only_precision(char *n, t_opt *o, char *sign, const int len)
{
	int		ret;
	int		sign_len;

	sign_len = (*sign != 0) + (sign[1] != 0);
	ret = sign_len;
	ret += (o->precision > len) ? o->precision : len;
	if (sign_len)
		ret = write(1, sign, sign_len);
	while (o->precision-- > len)
		write(1, "0", 1);
	write(1, n, len);
	return (ret);
}

inline int	print_number_with_options(char *n, t_opt *o, int neg)
{
	const int	len = ft_strlen(n);
	char		sign[2];

	get_sign(o, neg, sign);
	if (o->precision == -1)
	{
		if (o->width == -1)
		{
			o->width = 0;
			return (no_width_no_precision(n, sign, len));
		}
		return (width_only(n, o, sign, len));
	}
	if (o->width == -1)
	{
		o->width = 0;
		return (only_precision(n, o, sign, len));
	}
	return (width_and_precision(n, o, sign, len));
}
