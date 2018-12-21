/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   numeric_str_op.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 18:10:36 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 19:04:46 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

extern int		numeric_str_cmp(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;

	while (*s1 == '0' && s1[1])
		s1++;
	while (*s2 == '0' && s2[1])
		s2++;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (l1 > l2)
		return (1);
	else if (l1 < l2)
		return (-1);
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static void		add_overflow(char *s1, char *s2)
{
	int		rem;

	rem = (*s1 + *s2) - 96;
	while (1)
	{
		*s1 = (rem % 10) + 48;
		rem /= 10;
		if (!rem)
			break ;
		s1--;
		if (*s1 > 47 && *s1 < 58)
			rem = (*s1 + rem) - 48;
	}
}

extern int		numeric_str_add(char *s1, char *s2)
{
	char *curs;
	char *curs2;

	curs = s1 + ft_strlen(s1) - 1;
	curs2 = s2 + ft_strlen(s2) - 1;
	while (1)
	{
		if (*curs2 > 105 - *curs)
			add_overflow(curs, curs2);
		else
		{
			if (*curs > 47 && *curs < 58)
				*curs = *curs + *curs2 - 48;
			else
				*curs = *curs2;
		}
		if (curs2 == s2)
			break ;
		curs2--;
		curs--;
	}
	while (curs[-1])
		curs--;
	return (s1 - curs);
}

static void		sub_underflow(char *s1, char *s2)
{
	int		rem;

	rem = *s2 - *s1;
	*s1 = ((10 - rem) < 10) ? (10 - rem) + 48 : 48;
	s1--;
	while (1)
	{
		if (*s1 > 47 && *s1 < 58)
		{
			if (*s1 > '0')
			{
				*s1 -= 1;
				break ;
			}
			*s1 = '9';
			s1--;
			if (*s1 > '0')
			{
				*s1 -= 1;
				break ;
			}
			*s1 = '0';
		}
	}
}

extern int		numeric_str_sub(char *s1, char *s2)
{
	char		*curs;
	char		*curs2;

	curs = s1 + ft_strlen(s1) - 1;
	curs2 = s2 + ft_strlen(s2) - 1;
	while (1)
	{
		if (*curs2 > *curs)
			sub_underflow(curs, curs2);
		else
		{
			if (*curs > 47 && *curs < 58)
				*curs = *curs - *curs2 + 48;
			else
				*curs = *curs2;
		}
		if (curs2 == s2)
			break ;
		curs2--;
		curs--;
	}
	curs = s1;
	while (*curs == '0' && curs[1])
		curs++;
	return (curs - s1);
}
