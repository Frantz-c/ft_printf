/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 14:10:09 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 19:04:25 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#define BUFF_SIZE	2560

static char		*ft_crep(char *s, int c, int replace)
{
	if ((s = ft_strchr(s, c)) == NULL)
		return (NULL);
	*s = replace;
	return (s);
}

static char		*ft_strnfcat(char **s1, const char *s2, size_t size)
{
	char *new;

	if ((new = (char *)malloc(size + ft_strlen(*s1) + 1)) == NULL)
		return (NULL);
	ft_strcpy(new, *s1);
	free(*s1);
	ft_strncat(new, s2, size);
	*s1 = new;
	return (new);
}

static int		gomakashi(char *remainder)
{
	*remainder = '\0';
	return (-1);
}

static int		set_line(const int fd, char *remainder, char *buf, char **line)
{
	int		readl;
	char	*chrpos;

	while ((readl = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!*line)
			*line = ft_strdup("");
		buf[readl] = '\0';
		if ((chrpos = ft_memchr(buf, '\n', readl)) != NULL)
		{
			ft_memcpy(remainder, chrpos + 1, ft_strlen(chrpos + 1) + 1);
			if (!ft_strnfcat(line, buf, chrpos - buf))
				return (0);
			ft_crep(*line, '\n', '\0');
			return (1);
		}
		if (!ft_strnfcat(line, buf, readl + 1))
			return (0);
	}
	*remainder = '\0';
	return (*line ? 1 : 0);
}

extern int		get_next_line(const int fd, char **line)
{
	static char		remainder[BUFF_SIZE + 1];
	char			buf[BUFF_SIZE + 1];
	char			*chrpos;

	if (!line)
		return (gomakashi(remainder));
	if (*line)
		free(*line);
	*line = NULL;
	if (read(fd, buf, 0) < 0)
		return (-1);
	*buf = '\0';
	if (*remainder != '\0')
	{
		if ((chrpos = ft_strchr(remainder, '\n')) != NULL)
		{
			*line = ft_strndup(remainder, chrpos - remainder);
			ft_memmove(remainder, chrpos + 1, ft_strlen(chrpos + 1) + 1);
			return (1);
		}
		*line = ft_strdup(remainder);
	}
	return (set_line(fd, remainder, buf, line));
}
