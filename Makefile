# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 21:25:26 by ede-alme          #+#    #+#              #
#    Updated: 2022/04/15 18:00:57 by ede-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

CC = clang

FLAGS = -Wall -Wextra -Werror

SOURCE = jogo.c

OBJ = $(SOURCE:.c=.o)			

%.o: %.c
	$(CC) $(FLAGS) -fsanitize=address -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
#	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re main bonus