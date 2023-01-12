# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 17:00:30 by marvin            #+#    #+#              #
#    Updated: 2023/01/12 12:49:08 by miguelro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

#gcc -Wall -Wextra -Werror push_swap.c operations.c utils.c sort_3.c sort_5.c | .\a.exe

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

LIBFT = ./Library/Libft/libft.a
LIBFT_PATH = ./Library/Libft

FT_PRINTF = ./Library/Printf/libftprintf.a
FT_PRINTF_PATH = ./Library/Printf

INC = -I ./Library -I ./Library/Libft  -I ./Library/Printf

SRC_PATH = ./sources

OBJ_PATH = ./objects

SRC_NAME = push_swap.c operations.c utils.c sort_3.c sort_5.c sort_100.c\

OBJS = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))


all: $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_PATH)
	make -C $(FT_PRINTF_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(INC) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	echo "\x1b[36m[PUSH_SWAP COMPILED]\x1b[0m"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	mkdir -p objects
	$(CC) -c $(CFLAGS) $(Library) $< -o $@

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(FT_PRINTF_PATH)
	rm -rf $(OBJ_PATH)
	echo "\033[33mall $(NAME).o files are removed\033[0m"

fclean: clean
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(FT_PRINTF_PATH)
	rm -f $(NAME)
	echo "\033[31m$(NAME) is deleted\033[0m"

re: fclean all
