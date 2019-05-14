#ifndef FILIT_H
# define FILIT_H

# include "./gnl/get_next_line.h"
# include "./gnl/libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

int fill_figures(int fd);
int validation_check(int fd);

#endif