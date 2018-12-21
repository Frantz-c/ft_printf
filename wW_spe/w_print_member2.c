/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   y_print_member2.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 10:40:30 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 18:14:44 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "w_print_member.h"

inline int	print_str(int *offset, const char **s, void *ptr, int u)
{
	int		count;
	char	*p;

	(void)u;
	*offset += get_padding(*offset, sizeof(char*));
	if (**s == '=')
	{
		if ((p = ft_strchr(*s + 1, ',')) == NULL)
			p = ft_strchr(*s + 1, ';');
		count = ft_printf("(char *)%.*s = \"%s\"\n",
						(p - *s - 1), *s + 1, *(char**)(ptr + *offset));
		(*s) += (p - *s);
	}
	else
		count = ft_printf("[char *] = \"%s\"\n", *((char**)(ptr + *offset)));
	*offset += sizeof(char**);
	(*s)++;
	return (count);
}

inline int	print_char(int *offset, const char **s, void *ptr, int u)
{
	int		count;
	char	*p;

	*offset += get_padding(*offset, sizeof(char));
	if (**s == '=')
	{
		if ((p = ft_strchr(*s + 1, ',')) == NULL)
			p = ft_strchr(*s + 1, ';');
		count = (u) ? ft_printf("(uchar )%.*s = %hhu\n",
						(p - *s - 1), *s + 1, *(t_byte*)(ptr + *offset)) :
					ft_printf("(char  )%.*s = %hhu\n",
						(p - *s - 1), *s + 1, *(char*)(ptr + *offset));
		(*s) += (p - *s);
	}
	else
		count = (u) ? ft_printf("[uchar ] = %hhu\n",
							*(t_byte*)(ptr + *offset)) :
					ft_printf("[char  ] = %hhd\n", *(char*)(ptr + *offset));
	*offset += 1;
	(*s)++;
	return (count);
}

inline int	print_double(int *offset, const char **s, void *ptr, int u)
{
	int		count;
	char	*p;

	(void)u;
	*offset += get_padding(*offset, sizeof(double));
	if (**s == '=')
	{
		if ((p = ft_strchr(*s + 1, ',')) == NULL)
			p = ft_strchr(*s + 1, ';');
		count = ft_printf("(double)%.*s = %lf\n",
							(p - *s - 1), *s + 1, *(double*)(ptr + *offset));
		(*s) += (p - *s);
	}
	else
		count = ft_printf("[double] = %lf\n", *(double*)(ptr + *offset));
	*offset += sizeof(double);
	(*s)++;
	return (count);
}

inline int	print_float(int *offset, const char **s, void *ptr, int u)
{
	int		count;
	char	*p;

	(void)u;
	*offset += get_padding(*offset, sizeof(float));
	if (**s == '=')
	{
		if ((p = ft_strchr(*s + 1, ',')) == NULL)
			p = ft_strchr(*s + 1, ';');
		count = ft_printf("(float )%.*s = %f\n",
						(p - *s - 1), *s + 1, *(float*)(ptr + *offset));
		(*s) += (p - *s);
	}
	else
		count = ft_printf("[float ] = %f\n", *(float*)(ptr + *offset));
	*offset += sizeof(float);
	(*s)++;
	return (count);
}

inline int	print_ldouble(int *offset, const char **s, void *ptr, int u)
{
	int		count;
	char	*p;

	(void)u;
	*offset += get_padding(*offset, sizeof(t_ld));
	if (**s == '=')
	{
		if ((p = ft_strchr(*s + 1, ',')) == NULL)
			p = ft_strchr(*s + 1, ';');
		count = ft_printf("(double)%.*s = %Lf\n",
							(p - *s - 1), *s + 1, *(t_ld*)(ptr + *offset));
		(*s) += (p - *s);
	}
	else
		count = ft_printf("[ldouble] = %Lf\n", *(t_ld*)(ptr + *offset));
	*offset += sizeof(t_ld);
	(*s)++;
	return (count);
}
