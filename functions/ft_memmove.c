/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 15:38:59 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:28:08 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

extern void		*ft_memmove(void *dst, const void *src, size_t n)
{
	if ((long int)(dst - src) > 0)
		return (ft_memrcpy(dst, src, n));
	return (ft_memcpy(dst, src, n));
}
