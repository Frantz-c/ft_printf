/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 21:40:16 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:45:12 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

extern char		*ft_strstr(const char *str, const char *sub)
{
	long		equal;
	long		strsiz;
	const char	*str_start = str;
	const char	*sub_start = sub;
	const char	*p;

	equal = 1;
	while (*str && *sub)
		equal &= (*(str++) == *(sub++));
	if (*sub)
		return (NULL);
	if (equal)
		return ((char *)str_start);
	equal = sub - sub_start;
	str = str_start + 1;
	strsiz = (long)ft_strlen(str) - equal + 1;
	while (strsiz > -1 && (p = ft_memchr(str, *sub_start, (size_t)strsiz)))
	{
		if ((ft_strncmp(p, sub_start, equal)) == 0)
			return ((char *)p);
		strsiz -= p - str;
		str = p + 1;
	}
	return (NULL);
}
