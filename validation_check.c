/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:59:53 by tlorine           #+#    #+#             */
/*   Updated: 2019/06/13 19:55:44 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filit.h"

int		check_connect(char *figures, int i)
{
	int		con;

	con = 0;
	if (figures[i + 1] == '#')
		con++;
	if (figures[i - 1] == '#')
		con++;
	if (figures[i + 5] == '#')
		con++;
	if (figures[i - 5] == '#')
		con++;
	return (con);
}

int		check_laticce(char *figure)
{
	int		i;
	int		lattice;
	int		t;
	int		con;

	i = 0;
	lattice = 0;
	t = 0;
	con = 0;
	while (figure[i])
	{
		if (figure[i] == '#')
		{
			lattice++;
			con = con + check_connect(figure, i);
		}
		if (figure[i] == '.')
			t++;
		i++;
	}
	if (lattice != 4 || t != 12 || (con != 6 && con != 8))
		return (0);
	return (1);
}

int		figure_check(char *figure)
{
	int		i;
	int		n_check;

	n_check = 4;
	i = 0;
	while (figure[i] != '\0')
	{
		if (figure[i] != '\n' && figure[i] != '#' && figure[i] != '.')
			return (0);
		if ((figure[i] == '\n' && i != n_check && i != 20)
		|| (i == n_check && figure[i] != '\n'))
			return (0);
		else if (figure[i] == '\n' && i == n_check)
			n_check = n_check + 5;
		i++;
	}
	return (i);
}

int		validation_check(int fd)
{
	int		read_check;
	int		i;
	int		ch;
	char	figure[22];

	i = 0;
	ft_bzero(&figure, ft_strlen(figure));
	while ((read_check = read(fd, figure, 21)))
	{
		figure[read_check] = '\0';
		i = figure_check(figure);
		if ((ch = check_laticce(figure)) == 0 || i != 21)
		{
			if (ch == 0)
				return (0);
			if (read(fd, figure, 21) == 0 && i == 20)
				return (1);
			return (0);
		}
		ft_bzero(&figure, ft_strlen(figure));
	}
	if (read_check < 0 || i == 0 || i != 20)
		return (0);
	return (1);
}
