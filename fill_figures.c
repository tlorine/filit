#include "filit.h"

char *str_figures(int fd)
{
    char figures[22];
    char *buff;
    char *buff2;
    int read_count;
    int i;

    i = 0;
    buff = ft_strnew(1);
    while((read_count = read(fd, figures, 21)))
    {
        figures[read_count] = '\0';
        buff2 = buff;
        buff = ft_strjoin(buff2, figures);
        ft_strdel(&buff2);
    }
    return (buff);
    
}
int count_figures(char *figures)
{
    int i;
    int lat;
    int count;

    i = 0;
    lat = 0;
    count = 0;
    while (figures[i])
    {
        if (figures[i] == '#')
        {
            lat++;
        }
        i++;
    }
    count = lat / 4;
    return (count);
}

int fill_figures(int fd)
{
    char *figures;

    figures = str_figures(fd);
    return (0);
}