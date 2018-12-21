/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   w_global.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/16 15:21:15 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 19:03:31 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef W_GLOBAL_H
# define W_GLOBAL_H

# define TYPECOUNT	16

# include "w_print_member.h"

const char		*g_wtype[TYPECOUNT];
const int		g_wlen[TYPECOUNT];
const t_print	g_wprint[TYPECOUNT];

#endif
