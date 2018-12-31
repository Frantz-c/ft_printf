/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/20 14:53:14 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 09:35:57 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "ft_printf.h"

typedef struct	s_ls
{
	char		*name;
	size_t		size;
	int			inode;
	struct s_ls	*next;
}				t_ls;

int				main(void)
{
	t_ls	*tmp;
	int		tab[10] = {-1,2,-3,4,-5,6,-7,8,-9,10};
	t_uint	tab2[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 0};
	char	*s[] = {"un", "deux", "trois", "quatre", NULL};
	t_ls	*list = (t_ls *)malloc(sizeof(t_ls));

	tmp = list;
	list->name = ft_strdup("test.txt");
	list->size = 1089;
	list->inode = 99557214;
	list->next = (t_ls *)malloc(sizeof(t_ls));
	list = list->next;
	list->name = ft_strdup("main.c");
	list->size = 9185;
	list->inode = 91450027;
	list->next = (t_ls *)malloc(sizeof(t_ls));
	list = list->next;
	list->name = ft_strdup("main.h");
	list->size = 1184;
	list->inode = 96330225;
	list->next = NULL;
	list = tmp;
	printf("printf   : [%#.Lf][%.Lf]\n", 0.0l, 0.0l);
	ft_printf("ft_printf : [%#.Lf][%.Lf]\n", 0.0l, 0.0l);
    return (0);
	ft_printf("tab = %10y\n", tab);
	ft_printf("tab = %10.2Y\n", tab2);
	ft_printf("tab = %Z\n", s);
	ft_printf("tab = %#10y\n", tab);
	ft_printf("tab = %#10.2Y\n", tab2);
	ft_printf("tab = %#Z\n", s);
	ft_printf("list = %wchar*=name,size_t=size,int=inode,next;\n", list);
	ft_printf("list = %Ws_ls,main.c;\n", list);
    int c = ' ';
    while (c < 127)
    {
        ft_printf("[%d]'%c' = % hhb\n", c, c, c);
        c++;
    }
	free(list->next->next->name);
	free(list->next->next);
	free(list->next->name);
	free(list->next);
	free(list->name);
	free(list);

	return (0);
}
