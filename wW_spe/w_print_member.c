/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   y_print_member.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 10:39:02 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 18:14:34 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "w_print_member.h"

inline int	print_ptr(int *offset, const char **s, void *ptr, int u)
{
	int		count;
	char	*p;

	(void)u;
	*offset += get_padding(*offset, sizeof(void*));
	if (**s == '=')
	{
		if ((p = ft_strchr(*s + 1, ',')) == NULL)
			p = ft_strchr(*s + 1, ';');
		count = ft_printf("(void *)%.*s = %p\n",
				(p - *s) + 1, *s + 1, *(void**)(ptr + *offset));
		(*s) += (int)(p - *s);
	}
	else
		count = ft_printf("[void *] = %p\n", *(void**)(ptr + *offset));
	*offset += sizeof(void*);
	(*s)++;
	return (count);
}

inline int	print_long(int *off, const char **s, void *ptr, int u)
{
	int		count;
	char	*p;

	*off += get_padding(*off, sizeof(long));
	if (**s == '=')
	{
		if ((p = ft_strchr(*s + 1, ',')) == NULL)
			p = ft_strchr(*s + 1, ';');
		count = (u) ? ft_printf("(ulong )%.*s = %lu\n",
						(p - *s - 1), *s + 1, *(t_ulong*)(ptr + *off)) :
					ft_printf("(long  )%.*s = %ld\n",
						(p - *s - 1), *s + 1, *(long*)(ptr + *off));
		(*s) += (int)(p - *s);
	}
	else
		count = (u) ? ft_printf("[ulong ] = %lu\n", *(t_ulong*)(ptr + *off)) :
			ft_printf("[long  ] = %ld\n", *(long*)(ptr + *off));
	*off += sizeof(long);
	(*s)++;
	return (count);
}

inline int	print_int(int *offset, const char **s, void *ptr, int u)
{
	int		count;
	char	*p;

	*offset += get_padding(*offset, sizeof(int));
	if (**s == '=')
	{
		if ((p = ft_strchr(*s + 1, ',')) == NULL)
			p = ft_strchr(*s + 1, ';');
		count = (u) ? ft_printf("(uint  )%.*s = %u\n",
						(int)(p - *s - 1), *s + 1, *(t_uint*)(ptr + *offset)) :
					ft_printf("(int   )%.*s = %d\n",
						(int)(p - *s - 1), *s + 1, *(int*)(ptr + *offset));
		(*s) += (int)(p - *s);
	}
	else
		count = (u) ? ft_printf("[uint  ] = %u\n", *(t_uint*)(ptr + *offset)) :
			ft_printf("[int   ] = %d\n", *(int*)(ptr + *offset));
	*offset += sizeof(int);
	(*s)++;
	return (count);
}

inline int	print_short(int *offset, const char **s, void *ptr, int u)
{
	int		count;
	char	*p;

	*offset += get_padding(*offset, sizeof(short));
	if (**s == '=')
	{
		if ((p = ft_strchr(*s + 1, ',')) == NULL)
			p = ft_strchr(*s + 1, ';');
		count = (u) ? ft_printf("(ushort)%.*s = %hu\n",
						(p - *s - 1), *s + 1, *(t_ushort*)(ptr + *offset)) :
					ft_printf("(short )%.*s = %hd\n",
						(p - *s - 1), *s + 1, *(short*)(ptr + *offset));
		(*s) += (int)(p - *s);
	}
	else
		count = (u) ? ft_printf("[ushort] = %hu\n",
								*(t_ushort*)(ptr + *offset)) :
					ft_printf("[short ] = %hd\n", *(short*)(ptr + *offset));
	*offset += sizeof(short);
	(*s)++;
	return (count);
}

inline int	print_direct_str(int *offset, const char **s, void *ptr, int u)
{
	int		count;
	char	*p;

	(void)u;
	if (**s == '=')
	{
		if ((p = ft_strchr(*s + 1, ',')) == NULL)
			p = ft_strchr(*s + 1, ';');
		count = ft_printf("(uint  )%.*s = \"%s\"\n",
					(p - *s - 1), *s + 1, (char*)(ptr + *offset));
		(*s) += (int)(p - *s);
	}
	else
		count = ft_printf("[char *] = \"%s\"\n", ((char*)(ptr + *offset)));
	*offset += ft_strlen(((char*)(ptr + *offset)));
	(*s)++;
	return (count);
}
