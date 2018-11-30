/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_test.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 21:45:06 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 21:22:01 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_a
{
	char		*s;
	struct s_a	*next;
	int			a;
}				t_a;

int main(int argc, char **argv)
{
	int ret;
	int ret2;
	//long d = 123456789123456789;
	t_a *c = malloc(sizeof(t_a));
	char s1[] = "FRANTZ";
	char s2[] = "CORDON";
	long double a = 10.123;

	c->s = s1;
	c->a = 10;
	c->next = malloc(sizeof(t_a));
	c->next->s = s2;
	c->next->a = 13;
	c->next->next = NULL;

	/*
	printf("__STRUCT__ = %p\n", (void*)&c);
	printf("__STR__ = %p\n", (void*)c->s);
	printf("__A__ = %p\n", (void*)c->a);
	printf("__&A__ = %p\n", (void*)&c->a);
	printf("__NEXT__ = %p\n", (void*)c->next);
	printf("__STR2__ = %p\n", (void*)c->next->s);
	printf("sizeof(t_a) = %zu\n", sizeof(t_a));
	*/
	ft_printf("test : %ychar*,next,int;  << %w\n %#x .. %#X\n", (void*)c, a, 0, 0);
/*
	if (argc == 1) return (-1);
	ft_printf("ft_printf: \"");
	ret = ft_printf(argv[1], d);
	ft_printf("\"\n   printf: \"");
	ret2 = printf(argv[1], d);
	printf("\"\nft_printf : %d\n   printf : %d\n\n", ret, ret2);
*/
	return (0);
}
