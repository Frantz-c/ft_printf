/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 17:13:51 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:57:52 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

extern char		*ft_strndup(const char *s, size_t len)
{
	const size_t	end = ft_strnlen(s, len);
	char			*dup;

	if ((dup = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	ft_strncpy(dup, s, end);
	dup[end] = '\0';
	return (dup);
}
