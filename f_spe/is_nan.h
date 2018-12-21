/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   is_nan.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 20:08:57 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 19:04:03 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef IS_NAN_H
# define IS_NAN_H

# include "ulong128.h"
# include "../ft_printf.h"

int			is_inf_or_nan_ld(int sign, t_ulong n, char *buf);
int			is_inf_or_nan2(t_ulong128 *n, int sign, char *buf);

#endif
