/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:00:06 by tlorine           #+#    #+#             */
/*   Updated: 2019/06/13 20:29:22 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filit.h"

char	*str_figures(int fd)
{
	char	figures[22];
	char	*buff;
	char	*buff2;
	int		read_count;
	int		i;

	i = 0;
	buff = ft_strnew(1);
	while ((read_count = read(fd, figures, 21)))
	{
		figures[read_count] = '\0';
		buff2 = buff;
		buff = ft_strjoin(buff2, figures);
		free(buff2);
		buff2 = NULL;
	}
	return (buff);
}

int		count_figures(char *figures)
{
	int i;
	int lattice;
	int check;

	i = 0;
	lattice = 0;
	while (figures[i])
	{
		if (figures[i] == '#')
			lattice++;
		i++;
	}
	check = lattice / 4;
	if (check > 26)
	{
		write(1, "error\n", 6);
		return (-1);
	}
	return (0);
}

char	*create_k(int k)
{
	char	*kvadrat;
	int		size;
	int		i;
	int		g;

	i = 0;
	g = 0;
	size = k * k + k;
	kvadrat = (char *)malloc(sizeof(char) * size + 1);
	kvadrat[size] = '\0';
	while (i != size)
	{
		kvadrat[i] = '.';
		if (g == k)
		{
			kvadrat[i] = '\n';
			g = 0;
		}
		else
			g++;
		i++;
	}
	return (kvadrat);
}

int		fill_figures(int fd)
{
	char	*figures;

	figures = str_figures(fd);
	if (count_figures(figures) == -1)
		return (-1);
	coords(figures);
	return (0);
}
