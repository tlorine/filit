#include "filit.h"

int check_laticce(char *figure)
{
    int i;
    int lattice;
    int t;

    i = 0;
    lattice = 0;
    t = 0;
    while(figure[i])
        {
            if(figure[i] == '#')
            {
                lattice++;
                if (figure[i + 1] != '#' && figure[i - 1] != '#' && figure[i + 5] != '#' && figure[i - 5] != '#')
                    return (0);
            }
            if(figure[i] == '.')
                t++;
            i++;
        }
    if (lattice != 4 || t != 12)
        return (0);
    return (1);
}

int figure_check(char *figure)
{
    int i;
    int n_check;

    n_check = 4;
    i = 0;
    while(figure[i] != '\0')
        {
            if(figure[i] != '\n' && figure[i] != '#' && figure[i] != '.')
                return (0);
            if((figure[i] == '\n' && i != n_check && i != 20) || (i == n_check && figure[i] != '\n'))
                return (0);
            else if(figure[i] == '\n' && i == n_check)
               n_check = n_check + 5;
            i++;
        }
        return (i);
}

int validation_check(int fd)
{
    int read_check;
    int i;
    char figure[22]; 

    i = 0;
    ft_bzero(&figure, ft_strlen(figure));
    while((read_check = read(fd, figure, 21)))
    {
        figure[read_check] = '\0';
        i = figure_check(figure);
        if(check_laticce(figure) == 0 || i != 21)
        {
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