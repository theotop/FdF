# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlevaufr <tlevaufr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 14:10:22 by tlevaufr          #+#    #+#              #
#    Updated: 2018/03/21 18:09:07 by tlevaufr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

#Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

SRC = $(shell ls -1 | grep "\.c")
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS	= -Wall -Wextra -Werror
FRAMEWORKS = -framework AppKit -framework OpenGL

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./mlx/
	@make -C ../libft/
	@echo "\033[0m"
	@$(CC) $(CFLAGS) -I ../libft/ -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -lm -L ./mlx/ -L ../libft/ -lft -lmlx $(FRAMEWORKS)
	@echo "\033[1;5;1;36m";
	@echo "$(_RED)+------------------------+";
	@echo "|  $(_GREEN)______ _____  ______  $(_RED)|";
	@echo "| $(_GREEN)|  ____|  __ \|  ____| $(_RED)|";
	@echo "| $(_GREEN)| |__  | |  | | |__    $(_RED)|";
	@echo "| $(_GREEN)|  __| | |  | |  __|   $(_RED)|";
	@echo "| $(_GREEN)| |    | |__| | |      $(_RED)|";
	@echo "| $(_GREEN)|_|    |_____/|_|      $(_RED)|";
	@echo "|                        |";
	@echo "+------------by tlevaufr-+";
	@echo "\033[0m"

clean:
	make -C ../libft/ clean
	make -C ./mlx/ clean
	rm -f $(OBJ)

fclean: clean
	make -C ./mlx/ clean
	make -C ../libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY	:				all clean fclean re
