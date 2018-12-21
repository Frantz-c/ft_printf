/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_and_assign.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 17:19:10 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/20 11:07:02 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

extern void		*free_arg1_arg2_and_return_arg3(void *a1, void *a2, void *a3)
{
	if (a1)
		free(a1);
	if (a2)
		free(a2);
	return (a3);
}

extern void		assign_null_2a(void **a1, void **a2)
{
	*a1 = NULL;
	*a2 = NULL;
}
