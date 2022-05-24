CC =		gcc

NAME =		so_long

CFLAGS =	-fsanitize=address -Wall -Wextra -Werror

MLXFLAGS =	-lmlx -framework OpenGL -framework AppKit -o

SRCS =	main.c \
		window_prints.c \
		get_next_line.c \
		utils.c \
		keyboard.c \
		anim_game.c \
		./ft_printf/ft_printf.c \
		./ft_printf/ft_printf_utils.c \

OBJS =	$(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(MLXFLAGS) $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
