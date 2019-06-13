/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:37:09 by tlorine           #+#    #+#             */
/*   Updated: 2019/06/13 19:51:21 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filit.h"

int		free_coords(int **p)
{
	int count;

	count = 0;
	while (p[count])
	{
		free(p[count]);
		p[count] = NULL;
		count++;
	}
	return (0);
}

void	change_poz(int **p, int count, int op)
{
	if (op == 1)
	{
		p[count][0] = p[count][0] + 1;
		p[count][1] = p[count][1] + 1;
		p[count][2] = p[count][2] + 1;
		p[count][3] = p[count][3] + 1;
	}
	else if (op == -1)
	{
		p[count][0] = p[count][0] - 1;
		p[count][1] = p[count][1] - 1;
		p[count][2] = p[count][2] - 1;
		p[count][3] = p[count][3] - 1;
	}
}

char	*fill_square(int **p, char *square, int count, char c)
{
	if (c == 'A')
	{
		square[p[count][0]] = 'A' + count;
		square[p[count][1]] = 'A' + count;
		square[p[count][2]] = 'A' + count;
		square[p[count][3]] = 'A' + count;
		return (square);
	}
	square[p[count][0]] = '.';
	square[p[count][1]] = '.';
	square[p[count][2]] = '.';
	square[p[count][3]] = '.';
	return (square);
}

int		recursive_fill(int **p, char *square, int count)
{
	if (p[count] == NULL)
	{
		ft_putstr(square);
		return (0);
	}
	if (square[p[count][0]] == '.' && square[p[count][1]] == '.'
	&& square[p[count][2]] == '.' && square[p[count][3]] == '.')
	{
		square = fill_square(p, square, count, 'A');
		if (recursive_fill(p, square, count + 1) == 0)
			return (0);
		square = fill_square(p, square, count, '.');
	}
	if (square[p[count][3]] != '\0')
	{
		change_poz(p, count, 1);
		if (square[p[count][3]] != '\0')
		{
			if (recursive_fill(p, square, count) == 0)
				return (0);
		}
		change_poz(p, count, -1);
	}
	return (1);
}

int		finish(char *figures)
{
	int		*p[30];
	char	*square;
	int		s;

	s = 2;
	square = create_k(2);
	creat_mas(figures, square, p);
	while (recursive_fill(p, square, 0))
	{
		s++;
		ft_strdel(&square);
		square = create_k(s);
		free_coords(p);
		creat_mas(figures, square, p);
	}
	ft_strdel(&square);
	free_coords(p);
	ft_strdel(&figures);
	return (0);
}
