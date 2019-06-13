/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:00:03 by tlorine           #+#    #+#             */
/*   Updated: 2019/06/13 20:00:07 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filit.h"

int		near_lattice(char *figures, int i)
{
	int		latice;
	int		save_x;
	int		x;

	latice = 0;
	x = 0;
	while (latice != 4 && figures[i] != '\0')
	{
		if (figures[i] == '\n')
			x = -1;
		if (figures[i] == '#')
		{
			if (save_x > x || latice == 0)
				save_x = x;
			latice++;
		}
		x++;
		i++;
		if (figures[i] == '\0')
			return (-1);
	}
	return (save_x);
}

char	*f_left(char *figures)
{
	int		i;
	int		x;
	int		latice;

	i = 0;
	latice = 0;
	while (figures[i] != '\0')
	{
		x = near_lattice(figures, i);
		if (x == -1)
			return (figures);
		while (latice != 4 && figures[i] != '\0')
		{
			if (figures[i] == '#')
			{
				figures[i] = '.';
				figures[i - x] = '#';
				latice++;
			}
			i++;
		}
		latice = 0;
	}
	return (0);
}

int		latiice_poz(char *figures, char *square, int i, int *poz)
{
	int		line;
	int		x;
	int		laticce;

	laticce = 0;
	x = 0;
	line = 0;
	while (square[line] != '\n')
		line++;
	while (laticce != 4 && figures[i] != '\0')
	{
		if (figures[i] == '\n' && laticce == 0)
			x = -1;
		else if (figures[i] == '\n' && laticce != 0)
			x = (x + line + 1) - 5;
		if (figures[i] == '#')
		{
			poz[laticce] = x;
			laticce++;
		}
		i++;
		x++;
	}
	return (laticce == 4 ? 1 : 0);
}

int		creat_mas(char *figures, char *square, int **p)
{
	int count;
	int lat;
	int i;

	lat = 0;
	count = 0;
	i = 0;
	p[count] = (int *)malloc(sizeof(int) * 4);
	while (latiice_poz(figures, square, i, p[count]) == 1)
	{
		while (lat != 4)
		{
			if (figures[i] == '#')
				lat++;
			i++;
		}
		lat = 0;
		count++;
		p[count] = (int *)malloc(sizeof(int) * 4);
	}
	free(p[count]);
	p[count] = NULL;
	return (0);
}

int		*coords(char *figures)
{
	char	*buff;

	buff = f_left(figures);
	finish(f_left(figures));
	return (0);
}
