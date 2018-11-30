/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lf_specifier_functions.h                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 19:11:41 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 19:29:40 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ulong128.h"

t_ulong		get_integer_part(t_ulong n, t_ulong128 *integer,
									t_uint exp, t_ulong curs);
void		get_decimal_part(t_ulong n, t_ulong128 *decimal,
												t_ulong curs);
int			get_zero_decimal_part(t_ulong n, t_ulong128 *integer,
										t_ulong128 *decimal, t_uint n_loop);
int			to_big_double(long double n, t_opt *o, int sign);
