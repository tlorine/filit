/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:32:19 by tlorine           #+#    #+#             */
/*   Updated: 2019/06/13 20:12:37 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILIT_H
# define FILIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

int		fill_figures(int fd);
int		*coords(char *figures);
int		validation_check(int fd);
char	*create_k(int k);
int		finish(char *figures);
int		latiice_poz(char *figures, char *square, int i, int *poz);
int		creat_mas(char *figures, char *square, int **p);

#endif
