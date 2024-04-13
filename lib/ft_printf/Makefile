NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC = ft_printf.c check_type.c ft_putchar.c ft_strchr.c\
		ft_putstr.c ft_putnbr.c ft_putuns.c ft_puthex.c\
		ft_putptr.c

OBJ = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)