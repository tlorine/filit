NAME = libft.a
SRC = filit.c libft/ft_strjoin.c libft/ft_strnew.c libft/ft_strlen.c libft/ft_strchr.c libft/ft_strdel.c libft/ft_putendl.c libft/ft_putstr.c libft/ft_putchar.c libft/ft_putnbr.c fill_figures.c libft/ft_itoa.c libft/ft_bzero.c libft/ft_strdup.c validation_check.c coords.c finish.c
FLAGS = -Wall -Wextra -Werror
HED = filit.h
all:
	gcc $(FLAGS) $(SRC) -I $(HED)
clean:
	rm -f a.out
fclean: clean

re: fclean all