/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putn.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 19:00:11 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 18:38:14 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*llint_to_ascii(t_ullong n, char *s)
{
	while (1)
	{
		*(--s) = (n % 10) + 48;
		if (!(n /= 10))
			break ;
	}
	return (s);
}

extern int	u_spe(t_ullong n, t_opt *o)
{
	char	tmp[21];
	char	*ascii;

	o->flag &= 0x1a;
	if (n == 0 && o->precision == 0)
		return (print_number_with_options("", o, 0));
	tmp[20] = '\0';
	ascii = llint_to_ascii(n, tmp + 20);
	return (print_number_with_options(ascii, o, 0));
}

extern int	di_spe(long long n, t_opt *o)
{
	int			negative;
	t_ullong	number;
	char		tmp[21];
	char		*ascii;

	if (n == 0 && o->precision == 0)
		return (print_number_with_options("", o, 0));
	tmp[20] = '\0';
	if (n < 0)
	{
		negative = 1;
		number = (t_ullong)~n + 1;
	}
	else
	{
		number = (t_ullong)n;
		negative = 0;
	}
	if (o->precision == -1)
		o->precision = -2;
	ascii = llint_to_ascii(number, tmp + 20);
	return (print_number_with_options(ascii, o, negative));
}
