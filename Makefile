NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
LIBMLX	:= ./lib/MLX42/

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT	:= ./lib/libft/libft.a
PRINTF	:= ./lib/ft_printf/libftprintf.a
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@if [ ! -d "./lib/MLX42/" ]; then \
        cd ./lib && git clone https://github.com/codam-coding-college/MLX42.git; \
        cd ./MLX42 && cmake -B build && cmake --build build -j4; \
    fi
	make -C ./lib/libft 
	@make -C ./lib/ft_printf

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -I include $(LIBFT) $(PRINTF)  -o $(NAME)

clean:
	@make clean -C ./lib/libft 
	@make clean -C ./lib/ft_printf
	@rm -f $(OBJS)
	@rm -rf $(LIBMLX)/libmlx42.a
	@rm -rf ./lib/MLX42/

fclean: clean
	@make fclean -C ./lib/libft 
	@make fclean -C ./lib/ft_printf
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx