/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putn.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 19:00:11 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 16:08:37 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*llint_to_ascii(t_ullong n, char *s)
{
	while (1)
	{
		*(--s) = (n % 10) + 48;
		n /= 10;
		if (!n)
			break ;
	}
	return (s);
}

extern int	u_specifier(t_ullong n, t_opt *options)
{
	char	tmp[21];
	char	*ascii;

	if (!(options->length & LEN_L) && !(options->length & LEN_LL))
	{
		if (options->length & LEN_HH)
			n = (signed char)n;
		else if (options->length & LEN_H)
			n = (signed short int)n;
	}
	tmp[20] = '\0';
	ascii = llint_to_ascii(n, tmp + 20);
	return (print_number_with_options(ascii, options, 0));
}

extern int	di_specifier(long long int n, t_opt *options)
{
	int			negative;
	t_ullong	number;
	char		tmp[21];
	char		*ascii;

	if (options->length & LEN_HH)
		n = (signed char)n;
	else if (options->length & LEN_H)
		n = (signed short int)n;
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
	ascii = llint_to_ascii(number, tmp + 20);
	return (print_number_with_options(ascii, options, negative));
}
