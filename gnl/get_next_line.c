/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:02:10 by tlorine           #+#    #+#             */
/*   Updated: 2019/05/12 14:53:11 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_ost(char *s, size_t i)
{
	size_t	g;
	char	*d;

	g = 0;
	while (s[i] != '\0')
	{
		i++;
		g++;
	}
	if (!(d = (char *)malloc(sizeof(char) * (g + 1))))
		return (NULL);
	i = i - g;
	g = 0;
	while (s[i] != '\0')
	{
		d[g] = s[i];
		i++;
		g++;
	}
	d[g] = '\0';
	return (d);
}

static char	*fill_line(char *s, size_t i)
{
	size_t	g;
	char	*line;

	g = 0;
	if (!s)
		return (NULL);
	if (!(line = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (s[g] != '\n' && s[g] != '\0')
	{
		line[g] = s[g];
		i++;
		g++;
	}
	line[g] = '\0';
	return (line);
}

static int	gnl_main(char **s, char **line, int fd)
{
	char	*d;
	size_t	i;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = fill_line(s[fd], i);
		d = fill_ost(s[fd], i + 1);
		FS(s[fd], d);
		if (!s[fd][0])
			ft_strdel(&s[fd]);
		return (1);
	}
	*line = fill_line(s[fd], i);
	ft_strdel(&s[fd]);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			n;
	char		buf[BUFF_SIZE + 1];
	char		*d;
	static char	*s[12000];

	if ((fd < 0 || line == NULL || BUFF_SIZE == 0 || read(fd, buf, 0) < 0))
		return (-1);
	while ((n = read(fd, buf, BUFF_SIZE)))
	{
		buf[n] = '\0';
		if (!s[fd])
			s[fd] = ft_strnew(1);
		d = ft_strjoin(s[fd], buf);
		FS(s[fd], d);
		if (ft_strchr(buf, '\n'))
		{
			gnl_main(s, line, fd);
			return (1);
		}
	}
	if (!s[fd] || !s[fd][0])
		return (0);
	return (gnl_main(s, line, fd));
}
