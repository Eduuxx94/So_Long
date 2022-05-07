CC =		gcc

NAME =		so_long

CFLAGS =	-Wall -Wextra -Werror

MLXFLAGS =	-lmlx -framework OpenGL -framework AppKit -o

FSANITIZE =	-fsanitize=address

SRCS =	main.c \
		window_prints.c \
		get_next_line.c

OBJS =	$(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(FSANITIZE) $(CFLAGS) $(MLXFLAGS) $(NAME)


clean:
		@rm -f $(OBJS)
		@echo "$(NAME) $(OBJS): Foi Limpo!"

fclean:	clean
		@rm -f $(NAME)
		@echo "$(NAME): Foi Limpo!"

re: fclean all

.PHONY: all clean fclean re
