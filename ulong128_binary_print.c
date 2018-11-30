/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ulong128_binary_print.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 18:14:16 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 11:45:57 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

extern int		ulong128_print_binary(t_ulong128 *n)
{
	t_ulong		curs;
	char		buf[152];
	char		*ptr;

	ptr = buf + 151;
	*ptr = '\0';
	curs = 0x8000000000000000UL;
	while (curs)
	{
		*(--ptr) = (curs & n->hi) ? '1' : '0';
		if(curs & 0x0101010101010101UL)
			*(--ptr) = ' ';
		curs >>= 1;
	}
	*(--ptr) = ' ';
	curs = 0x8000000000000000UL;
	while (curs)
	{
		*(--ptr) = (curs & n->lo) ? '1' : '0';
		if(curs & 0x0101010101010100UL)
			write(1, " ", 1);
		curs >>= 1;
	}
	return (write(1, ptr, (151 + buf) - ptr));
}

extern int		ulong128_print_longd_binary(t_ulong128 *n)
{
	t_ulong		curs;
	char		buf[152];
	char		*ptr;

	ptr = buf;
	curs = 0x8000000000000000UL;
	while (curs)
	{
		*(ptr++) = (curs & n->hi) ? '1' : '0';
		if(curs & 0x0000000000000101UL)
			*(ptr++) = ' ';
		if (curs & 0x18001UL)
			*(ptr++) = '>';
		curs >>= 1;
	}
	curs = 0x8000000000000000UL;
	while (curs)
	{
		*(ptr++) = (curs & n->lo) ? '1' : '0';
		if(curs & 0x0101010101010100UL)
			*(ptr++) = ' ';
		curs >>= 1;
	}
	return (write(1, buf, ptr - buf));
}
