/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   y_specifier.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/30 17:54:02 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 21:07:51 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

//"%5y*void{int,int},next;"

static const char	*print_data(void *ptr, const char *s, t_opt *o, int *count)
{
	const char	*start = s;
	int			offset;
	void		*next;

	offset = 0;
	next = NULL;
	while (1)
	{
		// if (offset == 0) { printf("%p -> %p || %p -> %p\n", ptr, ptr + 8, *(void**)ptr, *(void**)(ptr + 8)); }
		if (!ft_strncmp(s, "*void", 5))
		{
			s = print_data(ptr + offset, s + 6, o, count);
			offset += sizeof(void*);
		}
		else if (!ft_strncmp(s, "void*", 5))
		{
			*count += ft_printf("[void*] = %p\n", *(void**)(ptr + offset));
			offset += sizeof(void*);
			s += 6;
		}
		else if (!ft_strncmp(s, "int", 3))
		{
			*count += ft_printf("[int  ] = %d\n", *(int*)(ptr + offset));
			offset += sizeof(int);
			s += 4;
		}
		else if (!ft_strncmp(s, "short", 5))
		{
			*count += ft_printf("[short] = %hd\n", *(short*)(ptr + offset));
			offset += sizeof(short);
			s += 6;
		}
		else if (!ft_strncmp(s, "char", 5))
		{
			*count += ft_printf("[char ] = %hd\n", *(char*)(ptr + offset));
			offset += sizeof(char);
			s += 6;
		}
		else if (!ft_strncmp(s, "char[]", 6))
		{
			*count += ft_printf("[char*] = \"%s\"\n", ((char*)(ptr + offset)));
			offset += sizeof(char*);
			s += 7;
		}
		else if (!ft_strncmp(s, "char*", 5))
		{
			*count += ft_printf("[char*] = \"%s\"\n", *((char**)(ptr + offset)));
			offset += sizeof(char**);
			s += 6;
		}
		else if (!ft_strncmp(s, "next", 4))
		{
			next = *(void**)(ptr + offset);
			//printf("\e[1;33mnext = %p\n\e[0m", next);
			offset += sizeof(void**);
			s += 5;
			continue ;
		}
		else if (!ft_strncmp(s, "pad", 3))
		{
			offset += s[3] - 48;
			s += 5;
		}
		else
		{
			if (s[-1] == '}')
				return (s);
			else if (s[-1] == ';')
			{
				offset = 0;
				if (next)
				{
					s = start;
					if (--o->width == 0)
						return (s);
					ptr = next;
					next = NULL;
					*count += write(1, "[next]\n\n", 8);
				}
				else
				{
					s = start;
					*count += write(1, "[end]\n", 6);
					return (s);
				}
			}
		}
	}
	return (s);	
}

int		y_specifier(void *ptr, t_opt *o, const char **fmt)
{
	int			count;

	if (o->width == 0)
		return (0);
	o->precision = 0;
	count = 0;
	write(1, "\n", 1);
	*fmt = print_data(ptr, *fmt + 1, o, &count);
	while (**fmt != ';')
		(*fmt)++;
	return (count);
}
