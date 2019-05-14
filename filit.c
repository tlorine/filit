/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:46:40 by tlorine           #+#    #+#             */
/*   Updated: 2019/05/14 16:43:36 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filit.h"

int main(int argc, char **argv)
{
    int fd;

    if(argc != 2)
    {
        if (argc != 2)
            write(1, "arguments", 9);
        return (0);
    }
    
    if((fd = open(argv[1], O_RDONLY)) < 0)
    {
        write(1, "error", 5);
        return (0);
    }
    if(validation_check(fd) == 0)
    {
        write(1, "error", 5);
        return (0);
    }
    close(fd);
    fd = open(argv[1], O_RDONLY);
    fill_figures(fd);
    return (1);
}