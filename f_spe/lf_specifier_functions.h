/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lf_specifier_functions.h                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 19:11:41 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 10:36:25 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LF_SPECIFIER_FUNCTIONS_H
# define LF_SPECIFIER_FUNCTIONS_H

# include "../ft_printf.h"
# include "ulong128.h"

t_ulong		get_integer_part(t_ulong n, t_ulong128 *integer,
									t_uint exp, t_ulong curs);
void		get_decimal_part(t_ulong n, t_ulong128 *decimal,
												t_ulong curs);
int			get_zero_decimal_part(t_ulong n, t_ulong128 *integer,
										t_ulong128 *decimal, t_uint n_loop);
int			to_big_long_double(long double n, t_opt *o, int sign);

#endif
