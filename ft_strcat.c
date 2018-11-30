/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 14:39:17 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/23 19:24:16 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcat(char *dst, const char *src)
{
	const size_t	dstsize = ft_strlen(dst);

	ft_strcpy(dst + dstsize, src);
	return (dst);
}
